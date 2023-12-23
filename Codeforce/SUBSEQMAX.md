Tại một đại hội thể thao quốc tế có n người xếp thành hàng dài và lần lượt đi qua khán đài chào khán giả. Người thứ i giữ một mã số ai có giá trị là một số nguyên. Alice quan sát và muốn biết một đoạn liên tiếp những người trong hàng có tổng các mã số lớn nhất là bao nhiêu.

Đề bài có thể tóm tắt như sau. Cho mảng s=(a1,...,an). Một đoạn s(i,j)=(ai,...,aj),1≤i≤j≤n. Trọng số w(i,j)=ai+ai+1...+aj

Yêu cầu:

Hãy tìm một đoạn trong mảng có trọng số lớn nhất, nghĩa là tổng các số trong đoạn là lớn nhất.

Input

```
Dòng thứ nhất chứa một số nguyên n≤106 
Dòng thứ hai chứa n số nguyên.
```

Output
```
Ghi ra duy nhất một số nguyên là trọng số lớn nhất tìm được.
```

````cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n = 0;
	cin>>n;
	
	// khoi tao mang arr[n]
	int arr[n];
	for (int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	// maxSum la gia tri tong toi da cua chuoi con dc tim thay tai thoi diem <= i
	// maxEnd : vvi tri ma chuoi con ket thuc
	int maxSum = arr[0];
	int maxEnd = arr[0];
	for (int i = 1; i<n; i++)
	{
		int u = arr[i];
		int v = arr[i] + maxEnd;
		if (u > v){
			maxEnd = u;
		}
		else
			maxEnd = v;
		if(maxEnd > maxSum)
		{
			maxSum = maxEnd;
		}
	}
	cout<<maxSum<<endl;
}
```