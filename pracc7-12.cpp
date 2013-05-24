#include <iostream>
 
using namespace std;
 
class String  {
private:
    char *pStr;
    int _length;
public:
    String()  {
        pStr = NULL;
        _length = 0;
    }
    String(char str[])  {
  	int _length=1;
		for (int i=0; str[i]!='\0'; ++i) ++_length;
		this->_length=_length+1;
		pStr=new char[this->_length];
		for (int i=0; i<(this->_length-1); ++i)
			pStr[i]=str[i];
		pStr[this->_length]='\0';
    }

	int SizeOf(){
		int _length=0;
		for (int i=0; pStr[i]!='\0'; ++i) _length++;
		return _length;
	}

    
	void Show(){
		for (int i=0; pStr[i]!='\0'; ++i)
			cout << pStr[i];
		cout << endl;
	}

	bool Equals(String str){
		if (this->_length==str._length) {
		int k=1;
		for (int i=0; pStr[i]!='\0'; ++i)
		{if (pStr[i]==str.pStr[i]) ++k;}
		if (k==this->_length) return true;
		else return false;}
		else return false;
	}
	
	bool BiggerThan(String str){
		if (this->Equals(str)==1) return false;
		for (int i=0; pStr[i]!='\0'; ++i)
		{if (pStr[i]==str.pStr[i]) continue;
		else if (pStr[i]>str.pStr[i]) return true;
		else return false;}
	}
	void DeleteAfter(int t){
	char *NEWpStr;
		NEWpStr=new char[t+1];
		for (int i=0; i<t; ++i)
			NEWpStr[i]=pStr[i];
		NEWpStr[t]='\0';
		pStr=NEWpStr;
	}
	void DeleteBefore(int t){
	char *NEWpStr;
		int k=this->SizeOf()-t+2;
		NEWpStr=new char[t];
		for (int i=0; i<(t+1); ++i)
			NEWpStr[i]=pStr[i+(t-1)];
		NEWpStr[t+1]='\0';
		pStr=NEWpStr;
	}
	void DeleteAfter(char t){
	int pos=1;
		for (int i=0; pStr[i]!='\0'; ++i)
		{
			if (pStr[i]==t) {pos=i+1; break;}
		}
		DeleteAfter(pos);
	}
	void DeleteBefore(char t){
	int pos=1;
		for (int i=0; pStr[i]!='\0'; ++i)
		{
			if(pStr[i]==t) {pos=i+1; break;}
		}
		DeleteBefore(pos);
	}
	
	void Replace(char *STR, char *_str){
			for (int i=0; pStr[i]!='\0'; ++i)
		{
			if(pStr[i]==STR[0]) {
				if(pStr[i+1]==STR[1])
					{pStr[i]=_str[0]; pStr[i+1]=_str[1]; break;}
		}
	}
}

	void Join(String str)
	{
	char *NEWpStr;
		int Q=this->SizeOf();
		int length=str.SizeOf();
			NEWpStr=new char[Q+length+1];
			NEWpStr[Q+length]='\0';
	for (int i=0; pStr[i]!='\0'; ++i){
		NEWpStr[i]=this->pStr[i];
		}
	for (int i=Q; NEWpStr[i]!='\0'; ++i){
		NEWpStr[i]=str.pStr[i-Q];}
		this->pStr=NEWpStr;
	}
    ~String()  {
		
    }
 
	
};
 
int main(int argc, char *argv[])  {
    String str("Banana");
	String EqualsStr("DADADADA");
	String BiggerThanStr("Orange-Juice");
    String HIGO ("Hi Jordan! ");
	String Joins(" FOOTBALL");
	String JoinStr("I LIKE");
	str.Show();
	int t = str.SizeOf();
	cout << t << endl;
	bool f = str.Equals(EqualsStr);
	cout << "\n" << f;
	bool g = str.BiggerThan(BiggerThanStr);
	cout << "\n" << g;
	/*cout << "\n" ; str.Show();
	str.DeleteAfter(2);
	cout << "\n" ; str.Show();*/
	cout << "\n" ; str.Show();
	str.DeleteBefore(2);
	cout << "\n" ; str.Show();
	BiggerThanStr.DeleteAfter('c');
	cout << "\n" ; BiggerThanStr.Show();
	/*BiggerThanStr.DeleteBefore('c');
	cout << "\n" ; BiggerThanStr.Show();*/
	JoinStr.Join(Joins);
	cout << "\n" ; JoinStr.Show();
	HIGO.Replace("Hi" , "Go");
	cout << "\n" ; HIGO.Show();
	cin.get();
    return 0;
}
