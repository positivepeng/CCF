#include<iostream>
#include<map>
using namespace std;
//one����key��value��two���浱ǰ��·����Ƕ�ײ�·��
map<string,string> one,two;

//�����ַ�����ȥ����б�ܣ�������i�����ã������������ 
string deal(int &i,string a)
{
	i++;
	string res="";
	while(1)
	{
		if(a[i]=='"')
			break;
		if(a[i]=='\\')
		{
			res+=a[i+1];
			i++;
		}
		else
			res+=a[i];
		i++;
	}
	return res;
}
int main()
{
	int n,m;
	cin >> n >> m;
	getchar();
	
	//line�������������ÿһ�У����㴦��name��ʾ��ǰ���·�� 
	string line="",temp,name="",key="",value="";
	
	//�������ÿһ���������������㴦�� 
	while(n--)
	{
		getline(cin,temp);
		line += temp;
	}
	int len = line.length();
	for(int i=1;i < len-1;i++)
	{
		//�����ո�Ͷ��� 
		if(line[i]==' ' || line[i]==',')
			continue;
		//������}����һ��Ƕ�׵Ľ�������ʱ��·��Ӧ�øĳɵ�ǰ���·�� 
		else if(line[i]=='}')
			name = two[name];
		//������"����ʾҪ����key�ˣ�����i�����ã��ں���������i��������key�ĵڶ��������� 
		else if(line[i]=='"')
			key = deal(i,line);
		//�����ˣ�����ʾҪ����value�� 
		else if(line[i]==':')
		{
			i++;
			//��ȥ������Ŀո� 
			while(line[i]==' ')
				i++;
			//�����������ַ������ȴ����ٴ浽map�� 
			if(line[i]=='"')
			{
				value=deal(i,line);
				//��ʱ�������key��·������ . ���� 
				one[name+"."+key]=value;
			}
			//��������value��Ƕ�׵Ķ��󣬾Ͱ�key��value��Ϊ OBJECT
			else if(line[i]=='{')
			{
				//��ʱ�������key��·������ . ���� 
				one[name+"."+key]="OBJECT";
				//����Ƕ�ײ�ǰ���Ƚ�Ƕ�ײ��·���͵�ǰ���·����Ӧ���� 
				two[name+"."+key]=name;
				//·���ĳ�Ƕ�ײ��·�� 
				name=name+"."+key;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		getline(cin,temp);
		//��Ϊ���ǵ�map�е�key�Ŀ�ͷ���и� . �����Բ�ѯʱ�ȼ��� 
		temp="."+temp;
		if(one.find(temp)!=one.end())
		{
			if(one[temp]=="OBJECT")
				cout<<"OBJECT"<<endl;
			else
				cout<<"STRING "<<one[temp]<<endl;
		}
		else
			cout<<"NOTEXIST"<<endl;
	}
	return 0; 
}

