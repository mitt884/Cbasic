#include <stdio.h>
#include <string.h>

// Hàm để chuyển đổi tên từ LastName-FirstName thành FirstName-LastName
void chuyenDoiTen(char ten[]) {
    // Tìm vị trí của ký tự khoảng trắng cuối cùng trong tên
    char *viTriKhoangTrangCuoi = strrchr(ten, ' ');
    
    // Nếu không tìm thấy ký tự khoảng trắng, thoát khỏi hàm
    if (viTriKhoangTrangCuoi == NULL) {
        return;
    }
    
    // Di chuyển con trỏ đến sau ký tự khoảng trắng cuối cùng
    viTriKhoangTrangCuoi++;
    
    // Tạo một mảng tạm thời để lưu trữ phần của tên từ sau ký tự khoảng trắng đầu tiên
    char phanTenTam[100];
    strcpy(phanTenTam, viTriKhoangTrangCuoi);
    
    // Gắn ký tự kết thúc chuỗi cho phần tên tạm thời
    phanTenTam[strlen(phanTenTam) - 1] = '\0';
    
    // Di chuyển con trỏ đến trước ký tự khoảng trắng cuối cùng
    viTriKhoangTrangCuoi--;
    
    // Dịch chuyển phần tên từ sau ký tự khoảng trắng cuối cùng sang phía trước
    while (ten != viTriKhoangTrangCuoi) {
        *viTriKhoangTrangCuoi = *(viTriKhoangTrangCuoi - 1);
        viTriKhoangTrangCuoi--;
    }
    
    // Gán phần tên tạm thời vào phần đầu của tên
    strcpy(ten, phanTenTam);
    
    // Thêm một khoảng trắng vào sau phần tên mới
    strcat(ten, " ");
    
    // Thêm phần tên từ trước ký tự khoảng trắng cuối cùng vào phía sau phần tên mới
    strncat(ten, ten, viTriKhoangTrangCuoi - ten);
}

int main() {
    char ten1[100], ten2[100];
    
    // Nhập tên của 2 học sinh
    printf("Nhap ten cua hoc sinh 1: ");
    fgets(ten1, sizeof(ten1), stdin);
    ten1[strlen(ten1) - 1] = '\0'; // Xóa ký tự newline ở cuối chuỗi
    
    printf("Nhap ten cua hoc sinh 2: ");
    fgets(ten2, sizeof(ten2), stdin);
    ten2[strlen(ten2) - 1] = '\0'; // Xóa ký tự newline ở cuối chuỗi
    
    // Chuyển đổi tên của 2 học sinh
    chuyenDoiTen(ten1);
    chuyenDoiTen(ten2);
    
    // In tên của 2 học sinh sau khi chuyển đổi
    printf("Ten hoc sinh 1 sau khi chuyen doi: %s\n", ten1);
    printf("Ten hoc sinh 2 sau khi chuyen doi: %s\n", ten2);
    
    return 0;
}
