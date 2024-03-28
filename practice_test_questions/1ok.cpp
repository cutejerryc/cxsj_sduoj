#include <iostream>
#include <algorithm>
using namespace std;

class Card
{
public:
    Card(int numbe,int sui):number(numbe),suit(sui){};
    Card(){};
    int suit;//花色
    int number;
    bool operator<(const Card &other) const{
        if (number == other.number)
        {
            return suit < other.suit;
        }
        else
        {
            return number < other.number;
        }
    }
};

class Deal
{
private:
    Card cards[1000000];
    Card target_cards[5];
    int result_count[9];

public:
    void init()
    {
        for (int i = 0; i < 9; i++)
        {
            result_count[i] = 0; // 初始化不同牌型出现次数的数组为0
        }
    }

    void evaluate()
    {
        sort(target_cards, target_cards + 5);//排序，便于找顺子
        int if_same_suit=1;//1同花
        int flush_suit = target_cards[0].suit;//同花的花色
        int if_straight = 1;//是否顺，1是
        int card_count[5];//牌的数字
        int card_number[5];//每个数字对应的牌的数量
        card_count[0] = target_cards[0].number;
        card_number[0] = 1;
        int different_number = 1;//不同数字的数量，初始为1
        for(int i=0;i<4; i++)
        {
            if ((target_cards[i + 1].number - target_cards[i].number) != 1)
            {
                if_straight = 0;//不连不是顺子
            }
            if (target_cards[i + 1].suit != flush_suit)
            {
                if_same_suit = 0;//不同花
            }
            int found = 0;
            for (int j = 0; j < different_number; j++)
            {
                if (target_cards[i + 1].number == card_count[j])
                {
                    card_number[j]++;//数量加1
                    found = 1;
                }
            }
            if (!found)
            {
                card_count[different_number] = target_cards[i + 1].number;
                card_number[different_number] = 1;
                different_number++;
            }
        }
        sort(card_number, card_number + different_number);//对牌的数量进行排序
        if (if_straight && if_same_suit)
        {//顺子和同花
            result_count[0]++;
        }else if (card_number[different_number - 1] == 4){//炸弹
            result_count[1]++;
        }else if ((card_number[different_number - 1] == 3 && card_number[different_number - 2] == 2)){//32
            result_count[2]++;
        }else if (if_same_suit){
            result_count[3]++;//同花
        }else if (if_straight){
            result_count[4]++;//顺子
        }else if (card_number[different_number - 1] == 3){
            result_count[5]++;//三条
        }else if (card_number[different_number - 1] == 2 && card_number[different_number - 2] == 2){
            result_count[6]++;//两对
        }else if (card_number[different_number - 1] == 2){
            result_count[7]++;//一对
        }else{
            result_count[8]++;
        }
    }
    void deal_cards(int A, int B, int a1, int b1, int a2, int b2)
    {
        Card target_card1(a1,b1), target_card2(a2,b2);
        int tmp = 0;
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < B; j++)
            {
                if ((i != a1 || j != b1) && (i != a2 || j != b2))
                {
                    Card current_card;
                    current_card.suit = j;
                    current_card.number = i;
                    cards[tmp] = current_card;
                    tmp++;
                }
            }
        }
        tmp -= 1;//减去多余的1
        int index1 = 0, index2 = 1, index3 = 2;
        while (index1 <= tmp - 2)
        {
            index2 = index1 + 1;
            while (index2 <= tmp - 1)
            {
                index3 = index2 + 1;
                while (index3 <= tmp)
                {
                    target_cards[0] = target_card1;
                    target_cards[1] = target_card2;
                    target_cards[2] = cards[index1];
                    target_cards[3] = cards[index2];
                    target_cards[4] = cards[index3];
                    evaluate();
                    index3++;
                }
                index2++;
            }
            index1++;
        }
    }

    void out_result()
    {
        for (int i = 0; i < 9; i++)
        {
            cout << result_count[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Deal deal;
    int A, B;
    int a1,b1,a2,b2;
    cin >> A >> B;
    cin >> a1 >> b1 >> a2 >> b2;
    deal.init();
    deal.deal_cards(A, B, a1, b1, a2, b2);
    deal.out_result();
    return 0;
}
