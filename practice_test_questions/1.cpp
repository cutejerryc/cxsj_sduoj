#include<bits/stdc++.h>
using namespace std;
class Card{
    public:
    int number;
    int suit;
    Card(int number1,int suit1):number(number1),suit(suit1){};
    Card(){};
    bool if_same_suit(const Card&other){
        return this->suit==other.suit;
    }
    bool if_same_number(const Card&other){
        return this->number==other.number;
    }
    bool if_same(int i,int u){
        return i==this->number&&u==this->suit;
    }
    bool if_same(const Card&other){
        return this->number==other.number&&this->suit==other.suit;
    }
    bool operator<(const Card& other) const {
        return number < other.number;
    }
    friend istream& operator>>(istream& input, Card& card) {
        input >> card.number>>card.suit;
        return input;
    }
};
class CardType{
    public:
    vector<Card>all_cards_selectable;
    vector<Card>all_cards;
    vector<vector<Card>>all_cards_two_dim;//另一种存储方式
    vector<Card>origin_cards;
    int A,B;
    Card card1,card2;
    CardType(){
        cin>>A>>B;
        cin>>card1>>card2;
        origin_cards.push_back(card1);
        origin_cards.push_back(card2);
        for(int i=0;i<A;i++){
            all_cards_two_dim.push_back(vector<Card>(0));
            for(int u=0;u<B;u++){
                all_cards.push_back(Card(i,u));
                if(!card1.if_same(i,u)&&!card2.if_same(i,u)){
                    all_cards_selectable.push_back(Card(i,u));
                    all_cards_two_dim[i].push_back(Card(i,u));
                }
            }
        }
    }
    int how_many_bomb(){//3.21 22:22
        int case_num=0;
        //two case
        if(card1.if_same_number(card2)){
            //需要选两个一样的出来
            for(int i=0;i<all_cards_selectable.size();i++){
                Card card_f=Card(all_cards_selectable[i]);
                for(int u=i+1;u<all_cards_selectable.size();u++){
                    if(all_cards_selectable[u].if_same(card_f)){
                        continue;
                    }
                    Card card_s=Card(all_cards_selectable[u]);
                    for(int j=u+1;j<all_cards_selectable.size();j++){
                        if(all_cards_selectable[j].if_same(card_f)||all_cards_selectable[j].if_same(card_s)){
                            continue;
                        }
                        //判断是否有其中的两个的数字相同
                        if((all_cards_selectable[i].if_same_number(card1)&&all_cards_selectable[u].if_same_number(card1))||(all_cards_selectable[i].if_same_number(card1)&&all_cards_selectable[j].if_same_number(card1))||(all_cards_selectable[j].if_same_number(card1)&&all_cards_selectable[u].if_same_number(card1))){
                            case_num++;
                        }
                    }
                }
            }
        }else{
            for(int j=0;j<origin_cards.size();j++){
                for(int i=0;i<all_cards_selectable.size();i++){
                    Card card_f=Card(all_cards_selectable[i]);
                    for(int u=i+1;u<all_cards_selectable.size();u++){
                        if(all_cards_selectable[u].if_same(card_f)){
                            continue;
                        }
                        Card card_s=Card(all_cards_selectable[u]);
                        for(int k=u+1;k<all_cards_selectable.size();k++){
                            if(all_cards_selectable[k].if_same(card_f)||all_cards_selectable[k].if_same(card_s)){
                                continue;
                            }
                            //判断是否存在4个一样数字的
                            if(origin_cards[j].if_same_number(card_f)&&origin_cards[j].if_same_number(card_s)&&origin_cards[j].if_same_number(all_cards_selectable[k])){
                                case_num++;
                            }
                        }
                    }
                }
            }
        }
        return case_num;
    }
    int how_many_three_pair(){
        int case_num=0;
        if(card1.if_same_number(card2)){
            for(int i=0;i<all_cards_selectable.size();i++){//最初选的作为pair，在选三个一样的
                for(int u=i+1;u<all_cards_selectable.size();u++){
                    for(int j=u+1;j<all_cards_selectable.size();j++){
                        if(all_cards_selectable[i].if_same_number(all_cards_selectable[u])&&all_cards_selectable[i].if_same_number(all_cards_selectable[j])){
                            case_num++;
                        }
                    }
                }
            }
            for(int i=0;i<B-2;i++){//最初选的作为three，再选两个一样的，注意排除与已经选的一样的情况
                for(int u=0;u<all_cards_selectable.size();u++){
                    for(int j=0;j<all_cards_selectable.size();j++){
                        if(!card1.if_same_number(all_cards_selectable[u])&&all_cards_selectable[u].if_same_number(all_cards_selectable[j])){
                            case_num++;
                        }
                    }
                }
            }
        }else{
            //第一张牌作为3张的
            for(int i=0;i<B-1;i++){//对于第一张牌，还有B-1种花色可以选择
                for(int u=i+1;u<B-1;u++){//选择第一张牌的第二种花色
                    for(int j=0;j<B-1;j++){//对于第二张牌的花色
                        case_num++;
                        //第二张牌作为三张的逻辑是一样的，所以在这里直接++
                        case_num++;
                    }
                }
            }
        }
        return case_num;
    }
    int how_many_same_suit(){//炸弹不可能是同花，三带二不可能是同花，最后计算需要排除同花顺的情况数
        int case_num=0;
        if(!card1.if_same_suit(card2)){
            //直接排除这种情况
        }else{//选牌娄
            for(int i=0;i<all_cards_selectable.size();i++){
                for(int u=i+1;u<all_cards_selectable.size();u++){
                    for(int j=u+1;j<all_cards_selectable.size();j++){
                        if(card1.if_same_suit(all_cards_selectable[i])&&card1.if_same_suit(all_cards_selectable[u])&&card1.if_same_suit(all_cards_selectable[j])){
                            case_num++;
                        }
                    }
                }
            }
        }
        return case_num;
    }
    int how_many_straight(bool if_need_same_suit=0){//计算顺子需要排除童话顺的情况
        int case_num=0;
        if(!card1.if_same_suit(card2)&&if_need_same_suit){
            return 0;
        }
        int dis=abs(card1.number-card2.number);
        Card card_s=card1<card2?card1:card2;
        Card card_l=card1<card2?card2:card1;
        if(dis==1){//两个挨着
            //向前选择
            if(card_s.number-3>=0){
                for(int i=0;i<B;i++){
                    for(int u=0;u<B;u++){
                        for(int j=0;j<B;j++){
                            if(if_need_same_suit){
                                if(i==u&&i==j&&card_s.suit==i){
                                    case_num++;
                                }
                            }else{
                                case_num++;
                            }

                        }
                    }
                }
            }
            //向后选择
            if(card_l.number+3<=A-1){
                for(int i=0;i<B;i++){
                    for(int u=0;u<B;u++){
                        for(int j=0;j<B;j++){
                            if(if_need_same_suit){
                                if(i==u&&i==j&&card_s.suit==i){
                                    case_num++;
                                }
                            }else{
                                case_num++;
                            }
                        }
                    }
                } 
            }
        }else if(dis==2){
            if(card_l.number+1<=A-1&&card_s.number-1>=0){//分别向前或者向后选择
                for(int i=0;i<B;i++){//选择中间的花色
                    for(int u=0;u<B;u++){//选择前面的花色
                        for(int j=0;j<B;j++){//后面的花色
                            if(if_need_same_suit){
                                if(i==u&&i==j&&card_s.suit==i){
                                    case_num++;
                                }
                            }else{
                                case_num++;
                            }
                        }
                    }
                }
            }
            if(card_s.number-2>=0){//向前选择两个
                for(int i=0;i<B;i++){//选择中间的花色
                    for(int u=0;u<B;u++){//选择前面的第一个花色
                        for(int j=0;j<B;j++){//前面第二个的花色
                            if(if_need_same_suit){
                                if(i==u&&i==j&&card_s.suit==i){
                                    case_num++;
                                }
                            }else{
                                case_num++;
                            }
                        }
                    }
                }
            }
            if(card_l.number+2<=A-1){
                for(int i=0;i<B;i++){//选择中间的花色
                    for(int u=0;u<B;u++){//选择后面第一个的花色
                        for(int j=0;j<B;j++){//后面第二个的花色
                            if(if_need_same_suit){
                                if(i==u&&i==j&&card_s.suit==i){
                                    case_num++;
                                }
                            }else{
                                case_num++;
                            }
                        }
                    }
                }  
            }
        }else if(dis==3){
            if(card_s.number-1>=0){//向前选择
                for(int i=0;i<B;i++){//选择中间第一个
                    for(int u=0;u<B;u++){//选择中间第二个
                        for(int j=0;j<B;j++){//选则前面
                            if(if_need_same_suit){
                                if(i==u&&i==j&&card_s.suit==i){
                                    case_num++;
                                }
                            }else{
                                case_num++;
                            }
                        }
                    }
                } 
            }
            if(card_l.number+1<=A-1){//向后选择
                for(int i=0;i<B;i++){//选择中间第一个
                    for(int u=0;u<B;u++){//选择中间第二个
                        for(int j=0;j<B;j++){//选则后面
                            if(if_need_same_suit){
                                if(i==u&&i==j&&card_s.suit==i){
                                    case_num++;
                                }
                            }else{
                                case_num++;
                            }
                        }
                    }
                }   
            }
        }else if(dis==4){
            for(int i=0;i<B;i++){//选择中间第一个
                for(int u=0;u<B;u++){//选择中间第二个
                    for(int j=0;j<B;j++){//选则中间第三个
                        if(if_need_same_suit){
                            if(i==u&&i==j&&card_s.suit==i){
                                case_num++;
                            }
                        }else{
                            case_num++;
                        }
                    }
                }
            }   
        }else{
            //不可能出现
        }
        return case_num;
    }
    int how_many_three(){
        int case_num=0;
        if(card1.if_same_number(card2)){//
            //这两张牌作为三条
            for(int i=0;i<B-2;i++){
                for(int u=0;u<all_cards_selectable.size();u++){
                    for(int j=u+1;j<all_cards_selectable.size();j++){
                        case_num++;
                    }
                }
            }
            //剩余的三张牌作为三条，这里就把三代二也酸进去了
            for(int i=0;i<all_cards_selectable.size();i++){
                for(int u=i+1;u<all_cards_selectable.size();u++){
                    for(int j=u+1;j<all_cards_selectable.size();j++){
                        if(all_cards_selectable[i].if_same_number(all_cards_selectable[u])&&all_cards_selectable[u].if_same_number(all_cards_selectable[j])){
                            case_num++;
                        }
                    }
                }
            }
        }else{
            //第一张牌作为三条
            for(int i=0;i<B;i++){
                for(int u=i+1;u<B;u++){
                    if(i!=card1.suit&&u!=card1.suit)
                    for(int j=0;j<all_cards_selectable.size();j++){
                        if(!all_cards_selectable[j].if_same(Card(card1.number,i))&&!all_cards_selectable[j].if_same(Card(card1.number,u))){
                            case_num+=2;
                        }
                    }
                }
            }
            //剩余的三张牌作为三条
            for(int i=0;i<all_cards_selectable.size();i++){
                for(int u=i+1;u<all_cards_selectable.size();u++){
                    for(int j=u+1;j<all_cards_selectable.size();j++){
                        if(all_cards_selectable[i].if_same_number(all_cards_selectable[u])&&all_cards_selectable[u].if_same_number(all_cards_selectable[j])){
                            case_num++;
                        }
                    }
                }
            }
        }
        return case_num;
    }
    int how_many_two_pair(){
        int case_num=0;
        return case_num;
    }
    int how_many_single_pair(){
        int case_num=0;
        return case_num;
    }
};
int main(){
    CardType ct=CardType();
    cout<<ct.how_many_bomb()<<' '<<ct.how_many_same_suit()<<' '<<ct.how_many_straight()<<' '<<ct.how_many_straight(1)<<' '<<ct.how_many_three_pair()<<' '<<ct.how_many_three();
}