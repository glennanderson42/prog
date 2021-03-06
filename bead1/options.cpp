#include "function.h"

using namespace std;

//optimistakereses
bool isColumnNonzero(const vector<vector<int> > &v,const int col) {
    bool no_zeros = true;
    int row = 0;
    while(no_zeros && row < v.size()) {
        no_zeros = v.at(row).at(col) > 0;
        ++row;
    }
    return no_zeros;
}

//Pesszimista kereses
bool existsVillageWithAllBirds(const vector<vector<int> > &v) {
    bool exist = false;
    int col = 0;
    while(!exist && col < v.at(0).size()) {
        exist = isColumnNonzero(v, col);
        ++col;
    }
    return exist;
}

vector<vector<int> > loadFromFile(vector<vector<int> > &data) {
        fstream fin;
        string filename;//= "input.txt";
        string temp;
        cin >> temp;
        filename = temp + ".txt";
        fin.open(filename.c_str());
        if(fin.fail() || !fin.is_open()) {
            throw WI;
        }
        else{
            fin >> data;
        }
    return data;
}

//Mátrixok beolvasása

template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &data)
{
    int r,c;
    in >> r >> c;
    if(in.fail()) {
        throw WI;
    }

    if(r < 0 || c < 0) {
        throw NC;
    }

    for(int i = 0; i < r; ++i) {
        T temp;
        temp.resize(c);
        in >> temp;
        data.push_back(temp);
    }
    return in;
}

istream& operator>>(istream& in, vector<int> &data) {
    for(int i = 0; i < data.size(); ++i) {
        int temp;
        in >> temp;

        if(in.fail()) {
            throw WI;
        }
        if(temp < 0) {
            throw WV;
        }
        data.at(i) = temp;
        }
    return in;
}

//mátrix kiíratása (csak ellenőrzés céljából van benne)

ostream& operator<<(ostream& out, const vector<vector<int> > &data)
{
    for(int i = 0; i < data.size(); ++i) {
        for(int j = 0; j < data.at(i).size(); ++j) {
            out << data.at(i).at(j) << " ";
        }
        out << endl;
    }
    return out;
}

//standard inputról való beolvasás(billentyűzetről)

vector<vector<int> > standardInput(vector<vector<int> > &data) {
          string tempke;
          int row,col;

          cin >> row >> col;
          if(cin.fail()) {
            throw WI;
            }

          if(row <= 0 || col <= 0) {
            getline(cin, tempke);
            cin.clear();
            cin.ignore(10000, '\n');
            throw NC;
            }
          int temp;

          data.resize(row);
          for(int i = 0; i < row; ++i) {
            data.at(i).resize(col);
                for(int j = 0; j < col; ++j) {
                    cin >> temp;
                    if(cin.fail()) {
                        getline(cin, tempke);
                        cin.clear();
                        cin.ignore(10000, '\n');
                        throw WI;
                    }

                    if(temp < 0) {
                        getline(cin, tempke);
                            cin.clear();
                            cin.ignore(10000, '\n');
                        throw WV;
                    }

                    data.at(i).at(j) = temp;
                    }
        }
    return data;
}


void echoMenu(vector<vector<int> > &data) {

    data.clear();

    bool menuSuccess=false;
    do{

        system("cls");
        cout << "||=============================================||" <<  endl;
        cout << "||" << "Valasszon a lehetosegek kozul: " << "              ||" << endl;
        cout << "||" << "1, Feladat leiras                            ||" << endl;
        cout << "||" << "2, Filebol valo beolvasas" << "                    ||" << endl;
        cout << "||" << "3, Standard inputrol valo beolvasas" << "          ||" << endl;
        cout << "||" << "4, Kilepes" << "                                   ||" << endl;
        cout << "||" << "Uss le egy billentyut" << "                        ||" << endl;
        cout << "||" << "=============================================" << "||" << endl;
        char input;
        input = getch();
        switch(input){
            case '1': {
                echoTask();
                menuSuccess = true;
                system("pause");
                break;
            }
            case '2': {
                cout << "Adja meg az input file nevet a .txt nelkul" << endl;
                readFromFile(data);
                menuSuccess = true;
                system("pause");
                break;
            case '3':{
                cout << "Irja be a sorok es az oszlopok szamat, majd a matrixot" << endl;
                readFromStandardInput(data);
                menuSuccess = true;
                system("pause");
                break;
                }
            }
            case '4':{
                cout << "Sikeresen kilepett a programbol" << endl;
                menuSuccess = true;
                exit(0);
                system("pause");
                break;
            }
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }while(!menuSuccess);
}
