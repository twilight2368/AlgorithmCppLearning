Điện thoại di động (ĐTDĐ) trở nên một phần không thể thiếu trong cuộc sống hiện đại. Ngoài việc gọi, ĐTDĐ có thể gửi tin nhắn mà người ta quen gọi là SMS. Không như bàn phím máy tính, đa phần ĐTDĐ cổ điển hạn chế số phím. Để có thể gõ được tất cả các ký tự trong bảng chữ cái, nhiều ký tự sẽ được hiển thị trên cùng một phím. Vì vậy, để gõ một số ký tự, một phím sẽ phải được ấn liên tục đến khi ký tự cần tìm hiển thị trên màn hình.

Cho một đoạn văn bản, hãy tính số lần gõ phím để hiển thị được đoạn văn bản.

Bài toán giả thiết rằng các phím được sắp xếp như sau
```
    abc  def 
ghi jkl  mno 
pqrs tuv wxyz
    <SP>
```
Trong bảng trên mỗi ô biểu diễn một phím. ```<SP>``` biểu diễn phím space. Để hiển thị ký tự 'a' thì sẽ phải bấm phím tương ứng 1 lần, nhưng để hiển thị ký tự 'b' của cùng phím đó thì sẽ phải bấm liên tục 2 lần và đối với phím 'c' là 3 lần. Tương tự, bấm 1 lần cho 'd', hai lần cho 'e' và 3 lần cho 'f'. Các ký tự khác cũng được làm tương tự. Lưu ý là để ra 1 khoảng trống thì cần bấm 1 lần phím space.

Input
Dòng đầu tiên là một số nguyên T
là số lượng trường hợp test. T
dòng tiếp theo mỗi dòng chỉ chứa các khoảng trống và các ký tự in thường. Mỗi dòng chứa ít nhất 1 và tối đa 100 ký tự.

Output
Mỗi trường hợp test đầu vào tương ứng với một dòng ở kết quả ra. Mỗi dòng bắt đầu bởi thứ tự trường hợp test và sau đó là một số biểu thị số lần bấm phím cho ra văn bản tương ứng. Xem ví dụ kết quả ra để thấy định dạng chuẩn xác.

Example

input

```
2
welcome to ulab
good luck and have fun
```

output

```
Case #1: 29
Case #2: 41
```
