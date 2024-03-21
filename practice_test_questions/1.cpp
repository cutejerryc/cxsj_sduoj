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
    friend istream& operator>>(istream& input, Card& card) {
        input >> card.number>>card.suit;
        return input;
    }
};
class CardType{
    public:
    vector<Card>all_cards;
    vector<Card>origin_cards;
    int A,B;
    Card card1,card2;
    CardType(){
        cin>>A>>B;
        cin>>card1>>card2;
        origin_cards.push_back(card1);
        origin_cards.push_back(card2);
        for(int i=0;i<A;i++){
            for(int u=0;u<B;u++){
                if(!card1.if_same(i,u)&&!card2.if_same(i,u)){
                    all_cards.push_back(Card(i,u));
                }
            }
        }
    }
    int how_many_flush(){
        int case_num=0;
        return case_num;
    }
    int how_many_bomb(){
        int case_num=0;
        //two case
        if(card1.if_same_number(card2)){
            //需要选两个一样的出来
            for(int i=0;i<all_cards.size();i++){
                Card card_f=Card(all_cards[i]);
                for(int u=0;u<all_cards.size();u++){
                    if(all_cards[u].if_same(card_f)){
                        continue;
                    }
                    Card card_s=Card(all_cards[u]);
                    for(int j=0;j<all_cards.size();j++){
                        if(all_cards[j].if_same(card_f)||all_cards[j].if_same(card_s)){
                            continue;
                        }
                        //判断是否有其中的两个的数字相同
                        if((all_cards[i].if_same_number(card1)&&all_cards[u].if_same_number(card1))||(all_cards[i].if_same_number(card1)&&all_cards[j].if_same_number(card1))||(all_cards[j].if_same_number(card1)&&all_cards[u].if_same_number(card1))){
                            case_num++;
                        }
                    }
                }
            }
        }else{
            for(int j=0;j<origin_cards.size();j++){
                for(int i=0;i<all_cards.size();i++){
                    Card card_f=Card(all_cards[i]);
                    for(int u=i+1;u<all_cards.size();u++){
                        if(all_cards[u].if_same(card_f)){
                            continue;
                        }
                        Card card_s=Card(all_cards[u]);
                        for(int k=u+1;k<all_cards.size();k++){
                            if(all_cards[k].if_same(card_f)||all_cards[k].if_same(card_s)){
                                continue;
                            }
                            //判断是否存在4个一样数字的
                            if(origin_cards[j].if_same_number(card_f)&&origin_cards[j].if_same_number(card_s)&&origin_cards[j].if_same_number(all_cards[k])){
                                case_num++;
                            }
                        }
                    }
                }
            }
        }
        return case_num;
    }
    int how_many_three_two(){
        int case_num=0;
        return case_num;
    }
    int how_many_same_suit(){
        int case_num=0;
        return case_num;
    }
    int how_many_straight(){
        int case_num=0;
        return case_num;
    }
    int how_many_three(){
        int case_num=0;
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
    cout<<ct.how_many_bomb();
}