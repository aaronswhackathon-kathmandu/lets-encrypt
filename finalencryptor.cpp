#include "iostream"
#include "fstream"
#include "string"
#include "string.h"
#include "cstring"
using namespace std;
ifstream fin;
ofstream fout;
string a = "externalfile.txt";	//get user input filename for reading
class process;
class DisplayText
{
	public:
	string ReadText;
	string DecryptedText;
	void Read()
	{
		
		fout<<DecryptedText;				
	}
};
class WriteText
{
	public: 
	string EncryptedText;
	string RawText;
	void GetText()
	{
	
			fin>>RawText;	
			
	}
	void Write()
	{
		
		fout<<EncryptedText;
		fout<<" ";	
		
	}

};

class process{	
	protected:
	string input;
	char output[100];
	
	public:
	process(string data)
	{
		input=data;
		
	}

	void displaydata(void)
	{
		cout<<"The word is"<<input;
	}
	string encrypt()
	{
		int j;
		
		int a=input.size();
		
		for (j=0;j<a;j++)
		{
			if (input[j]!=' ')
				output[j]=input[j]+a;
			else 
				break;
		}
		cout <<(string)output;
		return (string) output;
	}
	string decrypt()
	{
		int j;
		int a=input.size();
		
		for (j=0;j<a;j++)
		{
			output[j]=input[j]-a;
			
			
		}
		return(string) output;
	}
	
	
	
};


/*
main()
{
	string  c;
	string raw;
	cin>>raw;
	process one(raw);
	c=one.encrypt();
	cout<<c;
	process two(c);
	c=two.decrypt();
	cout<<c;

	

	
	
}
*/
	


int main()
{
	
	DisplayText disp_text;
	WriteText write_text;
	//main menu
	int n;
	cout<<endl<<"Choose one of the following:"<<endl<<endl;
	cout<<"\t 1. Encrypt A Text File"<<endl;
	cout<<"\t 2. Decrypt a Text File"<<endl;
	cout<<"\t 3. Exit Program"<<endl<<endl;
	cin>>n;
	switch (n)
	{
		case(1):
		{
			fin.open("externalfile.txt", ios::in);
			fout.open("encryptfile.txt", ios::out | ios::app);	//save encrypted words in a file	
			while (!fin.eof())
			{
			write_text.GetText();
			process a(write_text.RawText);
			//process a("apple");
			write_text.EncryptedText = a.encrypt();
			//cout<<a.encrypt();
			write_text.Write();
			} 
			fin.close();
			break;
		}
		case(2):
		{
		fout.open("decryptfile.txt", ios::out | ios::app);
		fin.open("encryptfile.txt", ios::in);
		while (!fin.eof())
			{
				fin>>disp_text.ReadText;
				process obj_process(disp_text.ReadText);
				disp_text.DecryptedText = obj_process.decrypt();
				disp_text.Read();
			}
			break;
		}
		case(3):
		{
			return 0;
		}
		default:
		;
	}
	cout<<endl<<"Task Completed Successfully."<<endl;
	char choice;
	cout<<endl<<"Exit?(y/n)";
	cin>>choice;
	if (choice=='y')
	return 0;
	else
	main();
}
