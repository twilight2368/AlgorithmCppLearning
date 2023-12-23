# ALGORITHMS Learning sessions

## Table of content
- [ALGORITHMS Learning sessions](#algorithms-learning-sessions)
  - [Table of content](#table-of-content)
  - [Backtracking](#backtracking)
  - [Branch and Bound](#branch-and-bound)

## Backtracking 

- Dùng để giải bài toán liệt kê các cấu hình. Mỗi cấu hình được xây dựng bằng từng phần tử. Mỗi phần tử lại được chọn bằng cách thử tất cả các khả năng.

- Mã giả:
```cpp
Backtracking(k) {
	for([Mỗi phương án chọn i(thuộc tập D)]) {
		if ([Chấp nhận i]) {
			[Chọn i cho X[k]];
			if ([Thành công]) {
				[Đưa ra kết quả];
			} else {
				Backtracking(k+1);
				[Bỏ chọn i cho X[k]];
			}
		}
	}
}

// X[-] : Lưu kết quả bài toán
```
## Branch and Bound
- Mã giả:

```cpp
void branch_and_bound(i)
{
    // Đánh giá các nghiệm mở rộng
    if ({Các_nghiệm_mở_rộng_đều_không_tốt_hơn_best_solution})
        return;
	
    for (value in S[i])
    {
        x[i] = value; // Ghi nhận thành phần thứ i.
		
        if ({Tìm_thấy_nghiệm})
            best_solution = X; // Cập nhật lại best_solution bằng nghiệm vừa tìm được.
        else 
            branch_and_bound(i + 1); // Chưa tìm thấy nghiệm thì xây dựng tiếp.
		
        {Loại_bỏ_thành_phần_thứ_i}
    }
}
```
