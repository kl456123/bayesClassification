#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}


void read(string& filename,int lines)
{
    fstream file(filename.c_str());
    string s;
    if(!file.is_open())
    {
        cout<<"error"<<endl;
        return;
    }
    int cot = 0;

    vector<vector<string> > fields;
    string c =", ";
    while(cot<lines&&!file.eof())
    {
        getline(file,s);

        vector<string > _field;


        SplitString(s,_field,c);
        fields.push_back(_field);

        for(int i=0; i<fields[cot].size(); i++)
        {
            cout<<fields[cot][i]<<endl;
        }
        cout<<endl;
        cot++;
    }


}





bool convertTrueOrFalse(const string& s)
{
    if(s.find("<="))
    {
        return true;
    }
    return false;
}






int main()
{
    string filename = "uci/adult.data";
    filename = "test.txt";

    read(filename,10000);
    cout<<convertTrueOrFalse(">50k");

    return 0;
}
