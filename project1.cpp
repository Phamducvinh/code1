#include <stdio.h>
void Nhap(int a[], int n){
    //dung vong lap for duyet tu vi tri index thu 0 cho den vi tri n - 1 
    for(int i = 0; i <= n - 1; i++){
        //nhap gia tri va gan vao tung phan tu a[i] cua mang
        printf("NHAP A[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
void Xuat(int a[], int n){
    printf("\nCAC PHAN TU CO TRONG MANG\n");
    for(int i = 0; i <= n - 1; i++){
        //xuat cac phan tu a[i] co trong mang ra man hinh
        printf("A[%d] = %d \n" ,i,a[i]);
    }
}
void ThemPhanTu(int a[], int index, int PhanTu, int &n){
    //neu index <= 0 thi gan index = 0 de them vao dau mang
    if(index <= 0){
        index = 0;
    }
    //neu index >= 10 thi gan index = 10 de them vao cuoi mang
    if(index >= n){
        index = n;
    }
    //dich chuyen cac phan tu 
    for(int i = n; i > index; i--){
        //dich chuyen phan tu sang ben trai
        a[i] = a[i-1];
    }
    //them phan tu 111 vao vi tri index 7
    a[index] = PhanTu;
    //tang kich thuoc mang len 1 don vi
    n++;
}

void TimKiem(int a[],int n, int phantu){
    //khai bao bien j de luu lai ket qua tim kiem
    int j;
    //duyet mang bang vong lap for
    for(int i = 0; i < n; i++){
        //neu co phan tu can tim kiem trong mang
        if(phantu == a[i]){
            //gan lai bien luu dia chi j bang dia chi thu i
            j = i;
            break;
        }
    }
    //neu j co gia tri dia chi tim kiem thi hien thi ket qua
    if(j != NULL || j >= 0){
        printf("TIM THAY PHAN TU %d TAI VI TRI %d", phantu, j);
    }else{
        printf("\nKHONG THAY PHAN TU %d", phantu, j);
    }
}
void SapXepTang(int a[], int n){
    //khai bao bien trung gian de hoan vi
    int trunggian;
    //thuc hien thuat toan sap xep chon
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j ++){
            //neu tim thay phan tu be hon phan tu dang xet thi doi cho 2 phan tu do cho nhau
            if(a[i] > a[j]){
                //hoan vi 2 phan tu
                trunggian = a[i];
                a[i] = a[j];
                a[j] = trunggian;
            }
        }
    }
}
void SapXepGiam(int a[], int n){
    //khai bao bien trung gian de hoan vi
    int trunggian;
    //thuc hien thuat toan sap xep chon
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j ++){
            //neu tim thay phan tu lon hon phan tu dang xet thi doi cho 2 phan tu do cho nhau
            if(a[i] < a[j]){
                //hoan vi 2 phan tu
                trunggian = a[i];
                a[i] = a[j];
                a[j] = trunggian;
            }
        }
    }
}

void DaoNguoc(int a[], int start, int end){
    //trong khi start < end thuc hien dao nguoc phan tu
    while (start < end)
    {
        //hoan vi phan tu tai vi tri start cho phan tu tai vi tri end
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        //tang start
        start++;
        //giam end
        end--;
    }
}


void XoaPhanTu(int a[], int &n, int index){
    //neu dia chi xoa nho hon 0 thi xoa phan tu dau tien
    if(index < 0){
        index = 0;
    }
    //neu dia chi xoa lon hon hoac bang n thi xoa phan tu cuoi cung
    if(index >= n){
        index = n - 1;
    }
    // Dich chuyen mang ve ben trai tu vi tri xoa
    for(int i = index; i < n - 1; i++){
        a[i] = a[i+1];
    }
    //sau khi xoa giam so luong phan tu mang
    n--;
}

int main(){
    //khai bao kich thuoc mang n 
    int n;
    //nhap vao n
    printf("NHAP N: ");
    scanf("%d",&n);
    //khai bao mang gom n phan tu
    int a[n];
    //goi ham nhap cac phan tu
    Nhap(a,n);
    //goi ham xuat
    Xuat(a,n);
    //nhap vao phan tu can them
    int PhanTu;
    printf("NHAP PHAN TU CAN THEM: ");
    scanf("%d",&PhanTu);
    //nhap vao vi tri can them
    int index;
    printf("NHAP VI TRI CAN THEM: ");
    scanf("%d",&index);
    //goi ham them phan tu truyen vao mang a,vi tri index can them, phan tu can them va  va so luong phan tu n cua mang
    ThemPhanTu(a,index, PhanTu, n);
    //goi ham xuat sau khi them phan tu
    Xuat(a,n);
   int phantu;
    printf("\nNHAP PHAN TU CAN TIM KIEM: ");
    scanf("%d",&phantu);
    //goi ham tim kiem
    TimKiem(a,n,phantu);
    
     //goi ham sap xep tang va hien thi mang sau khi sap xep tang
    SapXepTang(a,n);
    printf("\nMANG SAU KHI DUOC SAP XEP TANG DAN\n");
    Xuat(a,n);
    //goi ham sap xep giam va hien thi mang sau khi sap xep giam
    SapXepGiam(a,n);
    printf("MANG SAU KHI DUOC SAP XEP GIAM DAN\n");
    Xuat(a,n);
    
    //khai bao start = 0;
    int start = 0;
    //khao bao end = n - 1
    int end = n - 1;
    //goi ham dao nguoc
    DaoNguoc(a,start,end);
    printf("\n\nMANG DUOC DAO NGUOC\n");
    Xuat(a,n);
    
    
    printf("\nNHAP VI TRI CAN XOA: ");
    scanf("%d",&index);
    //goi ham xoa phan tu truyen vao mang can xoa, so luong phan tu va dia chi can xoa
    XoaPhanTu(a,n,index);
    //hien thi mang sau khi xoa tai vi tri index
    printf("\nMANG SAU KHI XOA TAI ARR[%d]\n", index);
    Xuat(a,n);
}

