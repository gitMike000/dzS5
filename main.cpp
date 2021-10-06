#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <list>
#include <regex>

using namespace std;

template <typename T,typename K>
void UniqWords(T it1, T it2, K d){
 cout.width(15);
 cout<<"WORDS";
 cout.width(15);
 cout<<"COUNT"<<endl;
 cout<<"-----------------------------------------"<<endl;
 map<K, int> freqs;
 T i;
 for(i=it1;i!=it2;i++) {
     ++freqs[*i];
 }  
 for(auto [s,i]:freqs) {
  cout.width(15);
  cout<<s;
  cout.width(15);
  cout<<i<<endl;
 };
 cout<<endl;
}

int main()
{
    // ----- Task 1 ---
    // Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов,
    // и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его
    // надо один раз). Продемонстрировать работу функции, передав итераторы различных типов.
    cout<<"Task 1"<<endl;

    {ifstream fs_st("/home/mike/git/dzS5/War.txt");
    string text;
    vector<string> words;
    while (fs_st >> text) {
        words.push_back(text);
    }
//    UniqWords(words.begin(),words.end());
    UniqWords(words.begin(),words.end(),text);

    ifstream fs_int("/home/mike/git/dzS5/number.txt");
    int a;
    vector<int> num;
    while (fs_int >> a) {
        num.push_back(a);
    }
    UniqWords(num.begin(),num.end(),a);

    ifstream fs_lint("/home/mike/git/dzS5/numberd.txt");
    list<double> li;
    double b;
    while (fs_lint >> b) {
        li.push_back(b);
    }
    UniqWords(li.begin(),li.end(),b);

    cout<<endl<<endl;}

    // ----- Task 2 ---
    // Используя ассоциативный контейнер, напишите программу, которая будет считывать данные
    // введенные пользователем из стандартного потока ввода и разбивать их на предложения.
    // Далее программа должна вывести пользователю все предложения, отсортировав их по длине.
    {cout<<"Task 2"<<endl;

    map<int,string> vs1;
    string s="1";
    string text="";
    while(s!="end")
    {
        cout<<"enter text, use dot(.) for the sentence to complete. (enter 'end' for finish):"<<endl;
        getline(cin,s);

        if(s!="end") {
  //s="War and Peace is the most famous and at the same time the most daunting of Russian novels, as vast as Russia itself and as long to cross from one end to the other. Yet if one makes the journey, the sights seen and the people met on the way mark one’s life forever. The book is set in the period of the Napoleonic wars (1805–1812) and tells of the interweaving of historical events with the private lives of two very different families of the Russian nobility—the severe Bolkonskys and the easygoing Rostovs—and of a singular man, reminiscent of the author himself—Count Pierre Bezukhov. It embodies the national myth of “Russia’s glorious period,” as Tolstoy himself called it, in the confrontation of the emperor Napoleon and Field Marshal Kutuzov, and at the same time it challenges that myth and all such myths through the vivid portrayal of the fates of countless ordinary people of the period, men and women, young and old, French as well as Russian, and through the author’s own passionate questioning of the truth of history. Tolstoy wrote that he “spent five years of ceaseless and exclusive labor, under the best conditions of life,” working on War and Peace. Those were the years from 1863 to 1868. He was thirty-five when he began. The year before, he had married Sofya Behrs, the daughter of a Moscow doctor, who was eighteen, and they had moved permanently to his estate at Yasnaya Polyana, in Tula province, a hundred and twenty miles south of Moscow. She bore him four children while he worked on the book, was his first reader (or listener), and was in part the model for his heroine, Natasha Rostov. Hello";
            unsigned long l_pos=0,h_pos=0;
            do {
              h_pos=s.find('.',l_pos);
              if (h_pos==-1) {text+=s.substr(l_pos,s.size())+" "; break;}
              text+=s.substr(l_pos,(h_pos-l_pos));
              l_pos=++h_pos;
              text = regex_replace(text, std::regex("^ +| +$|( ) +"), "$1");
              vs1[text.size()]=text;
              text="";
            } while (h_pos<s.size());

        }
    }
    if (text.size()!=0) {
        text = regex_replace(text, std::regex("^ +| +$|( ) +"), "$1");
        vs1[text.size()]=text;
    }
    cout<<endl<<endl;

    for(auto [i,s]:vs1) cout<<s<<endl<<"lenght="<<i<<endl<<endl;

    cout<<endl<<endl;}


    return 0;
}
