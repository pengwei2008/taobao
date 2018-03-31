//文件读写
int main()
{
	int x;
	vector<int> data;
	
	ifstream in("C:\\data.txt");
	if(!in)
	{
		cout<<"file error"<<endl;
		return 0;
	}
	
	while(!in.eof())
	{
		in>>x;
		data.push_back(x);
	}
	
	sort;
	
	in.close();
	
	ofstream out("C:\\result.txt");
	if(!out)
	{
		cout<<"file error"<<endl;
		return 0;
	}
	
	for(int i=0; i<data.size(); i++)
	{
		out<<data[i]<<"";
	}
	
	out.close();
	
	return 0;
}



//选择排序
void SelectSort(int a[], int n)
{
	int x;
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=i; j<n; j++)
		{
			if(a[j]<a[i])
				x=j;
		}
		swap(a[i], a[x]);
	}
}



//堆排序
void AdjustHeap(int a[], int x, int n)
{
	if(x>=n/2)
	{
		return;
	}
	
	int i=2*x+1;
	
	if(i+1<n && a[i]<a[i+1])
	{
		i++;
	}
	
	if(a[i]>a[x])
		exchange;
	
	AdjustHeap(a, i, n);
	
}

void HeapSort(int a[], int n)
{
	for(int i=n/2-1; i>=0; i--)
	{
		AdjustHeap(a, i, n);
	}
	
	for(int i=n-1; i>0; i--)
	{
		exchange;
		AdjustHeap(a, 0, i);
	}
}



//快速排序
int OnceQuickSort(int a[], int low, int high)
{
	int x=a[low];
	
	while(high>low && a[high]>=x)
	{
		high--;
	}
	a[low]=a[high];
	
	while(high>low && a[low]<=x)
	{
		low++;
	}
	a[high]=a[low];
	
	a[low]=x;
	return low;
}

void FastSort(int a[], int low, int high)
{
	if(low>=high)
	{
		return;
	}

	int mid=OnceQuickSort(a, low, high);
	Sort(a, low, mid);
	Sort(a, mid+1, high);
	
}



//String类实现
class String
{
	private:
	char *m_data;
	
	public:
	String(const char *str);
	String(const String &str);
	const String & operator = (const String &str);
	~String();
};

String::String(const char *str)
{
	if(str==NULL)
	{
		m_data=new char[1];
		*m_data='\0';
	}
	else
	{
		int len=strlen(str);
		m_data=new char[len+1];
		strcpy(m_data, str);
	}
}

String::String(const String &str)
{
	int len=strlen(str.m_data);
	m_data=new char[len+1];
	strcpy(m_data, str.m_data);
}

const String& String::operator =(const String &str)
{
	if(this==&str)
	{
		return *this;
	}
	
	delete []m_data;
	int len=strlen(str.m_data);
	m_data=new char[len+1];
	strcpy(m_data, str.m_data);
	return *this;
}

String::~String()
{
	delete []m_data;
}



//链表反转
Node* ReverseList(Node *head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	
	Node *p1, *p2, *p3;
	p1=head;
	p2=p1->next;
	p3=p2->next;
	
	p1->next=NULL;
	
	while(p3!=NULL)
	{
		p2->next=p1;
		p1=p2;
		p2=p3;
		p3=p3->next;
	}
	
	p2->next=p1;
	
	head=p2;
	return head;
}



//链表合并
Node *Merge(Node *p1, Node*p2)
{
	if(p1==NULL)
	{
		return P2;
	}
	
	if(p2==NULL)
	{
		return p1;
	}
	
	Node *p;
	
	if(p1->data<=p2->data)
	{
		p=p1;
		p->next=Merge(p1->next, p2);
	}
	else
	{
		p=p2;
		p->next=Merge(p1, p2->next);
	}
	
	return p;
}



//字符拷贝
void strcpy(char *dest, char *src)
{
	if(dest==NULL || src==NULL)
		return;
	
	while((*dest++=*src++)!='\0');
}



//平衡二叉树的插入
Tree* BinaryInsert(Tree *Head, int key)
{
	if(Head==NULL)
	{
		Head=new Tree;
		Head->data=key;
		Head->left=NULL;
		Head->right=NULL;
		return Head;
	}
	
	if(Head->data > key)
	{
		Head->left=BinaryInsert(Head->left, key);
	}
	else
	{
		Head->right=BinaryInsert(Head->right, key);
	}
	
	return Head;
}



//m_data清空
map<string, int> m_data;
m_data.insert(pair<string, int>("A", 10));
for(it=m_data.begin(); it!=m_data.end();)
{
	it=m_data.erase(it);
}



//插入排序
void InsertSort(int a[], int n)
{
	int i, j;
	int x;
	for(i=1;i<n;i++)
	{
		j=i;
		x=a[j];
		while(j>0 && x<a[j-1])
		{
			a[j]=a[j-1];
			j--;
		}
		
		a[j]=x;
	}
}



//二分查找
int binarysearch(int a[], int n, int x)
{
	int low=0;
	int high=n-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x==a[mid])
		{
			return mid;
		}
		else if(x>a[mid])
		{
			low=mid+1;
		}
		else if(x<a[mid])
		{
			high=mid-1;
		}
	}
	
	return -1;
}