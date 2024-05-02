#include <stdio.h>
#include <string.h>

void printReversedName(char *name) {
    int lastSpaceIndex = -1; // Khởi tạo biến lưu vị trí khoảng trắng cuối cùng
    char temp[50];
    // Tìm vị trí khoảng trắng cuối cùng trong chuỗi
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == ' ') {
            lastSpaceIndex = i; // Cập nhật vị trí khoảng trắng cuối cùng
        }
    }

    for(int i=0; i < lastSpaceIndex; i++){
        temp[i]=name[i];
    }
    temp[lastSpaceIndex] = '\0';

    //sb $t2, 0($lastspaceIndex)
    //sll $lastspaceIndex, $lastspaceIndex, 2

    if (lastSpaceIndex != -1) { 
        // In ra tên trước họ 
        printf("%s %s\n", name + lastSpaceIndex + 1, temp); 
    } else { 
        // Nếu không có khoảng trắng, chỉ in ra chuỗi ban đầu 
        printf("%s\n", name);
    }
}


int main() {
    char name[100];

    printf("Nhập tên: ");
    fgets(name, sizeof(name), stdin);

    printReversedName(name);

    return 0;
}

