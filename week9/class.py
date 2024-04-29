from torch import Tensor
device="cuda:0"
def extract_features(img:str):
    img=os.path.join(imgs_dir,img)
    image=Image.open(img)
    with torch.no_grad():
        image=preprocess(image).unsqueeze(0).to(device)
        image_features=model.encode_image(image)
        image_features/=image_features.norm(dim=-1,keepdim=True)
        image_features=image_features
    torch.cuda.empty_cache()
    return image_features.to(device_cpu)[0]
#用于计算两个向量之间的相似度
#移到cpu
from sklearn.cluster import KMeans
def get_class_imgs(id:int):
    class_index=[i for i in range(len(train_labels)) if train_labels[i]==id]
    features=[]
    for i in (class_index):
        features.append(extract_features(train_imgs[i]))
    features=np.array(features)
    kmeans = KMeans(n_clusters=4)
    kmeans.fit(features)
    most_similar_indexes=[]
    for i in range(4):
        cluster_indices=np.where(kmeans.labels_==i)[0]
        distances=np.abs(features[cluster_indices]-kmeans.cluster_centers_[i])
        distances=np.array([np.sum(distances**2) for i in range(distances.shape[0])])
        most_similar_indexes.append(cluster_indices[np.argmin(distances)])
    
    features_tensor = torch.tensor(features)
    try:
        existing_features = torch.load('./com_1/SVM/train_img_features.pt')
        updated_features = torch.cat((existing_features, features_tensor), dim=0)
        torch.save(updated_features, './com_1/SVM/train_img_features.pt')
    except FileNotFoundError:
        torch.save(features_tensor, './com_1/SVM/train_img_features.pt')
    except Exception as e:
        print("can't find .pt->")
        print(e)
    return most_similar_indexes
#
pre_id_sum=0
class_nums=len(set(train_labels))
selected_imgs=[]
selected_img_labels=[]
for i in tqdm([i for i in range(class_nums)]):
    class_image_ids=get_class_imgs(i)
    for u in class_image_ids:
        selected_imgs.append(train_imgs[pre_id_sum+u])
        selected_img_labels.append(train_labels[pre_id_sum+u])
    pre_id_sum=pre_id_sum+len([k for k in range(len(train_labels)) if train_labels[k]==i])
print(selected_imgs[:10])
with open('./com_1/SVM/selected_class.txt','w') as f:
    for i in range(len(selected_imgs)):
        f.write(str(selected_imgs[i])+' '+str(selected_img_labels[i])+'\n')
    f.close()