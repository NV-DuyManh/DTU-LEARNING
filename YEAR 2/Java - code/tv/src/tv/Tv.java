package tv;

import java.util.*;
import java.io.IOException;

interface ITV{
	double calculatre_sumtotal();
}

abstract class TV implements ITV{
    public String tvID;
    public String mainFacturer;
    public String entryDate;
    public double price;
    public double num;

    public TV() {}

    public TV(String tvID, String mainFacturer, String entryDate, double price, double num) {
        this.tvID = tvID;
        this.mainFacturer = mainFacturer;
        this.entryDate = entryDate;
        this.price = price;
        this.num = num;
    }

    public String getTvID() {
        return this.tvID;
    }

    public String getMainFacturer() {
        return this.mainFacturer;
    }

    public String getEntryDate() {
        return this.entryDate;
    }

    public double getPrice() {
        return this.price;
    }

    public double getNum() {
        return this.num;
    }

    public void setTvID(String tvID) {
        this.tvID = tvID;
    }

    public void setMainFacturer(String mainFacturer) {
        this.mainFacturer = mainFacturer;
    }

    public void setEntryDate(String entryDate) {
        this.entryDate = entryDate;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setNum(double num) {
        this.num = num;
    }

    public void input() {
        Scanner qq = new Scanner(System.in);
        System.out.print("Enter tvID: ");
        tvID = qq.nextLine();
        qq.nextLine();
        System.out.print("Enter mainFacturer: ");
        mainFacturer = qq.nextLine();
        qq.nextLine();
        System.out.print("Enter entryDate: ");
        entryDate = qq.nextLine();
        qq.nextLine();
        System.out.print("Enter price: ");
        price = qq.nextDouble();
        System.out.print("Enter num: ");
        num = qq.nextDouble();
    }

    public void output() {
        System.out.println("   tvID: " + this.tvID);
        System.out.println("   mainFacturer: " + this.mainFacturer);
        System.out.println("   entryDate: " + this.entryDate);
        System.out.println("   price: " + this.price);
        System.out.println("   num: " + this.num);
    }

    public double discount() {
        return 0;
    }

    public double sumTotal() {
        return this.num * this.price - this.discount();
    }
}

class TV_SAMSUNG extends TV {
    public String state;

    public TV_SAMSUNG() {}

    public TV_SAMSUNG(String tvID, String mainFacturer, String entryDate, double price, double num, String state) {
        super(tvID, mainFacturer, entryDate, price, num);
        this.state = state;
    }

    public String getState() {
        return this.state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public double discount() {
        if (this.state.equals("new")) {
            return this.num * this.price * 10 / 100;
        } else {
            return this.num * this.price * 60 / 100;
        }
    }

    public void input() {
        super.input();
        Scanner ww = new Scanner(System.in);
        System.out.print("Enter state: ");
        state = ww.nextLine();
    }

    public void output() {
        super.output();
        System.out.println("   state: " + this.state);
    }
}

class TV_SONY extends TV {
    public double surcharge;

    public TV_SONY() {}

    public TV_SONY(String tvID, String mainFacturer, String entryDate, double price, double num, double surcharge) {
        super(tvID, mainFacturer, entryDate, price, num);
        this.surcharge = surcharge;
    }

    public double getSurcharge() {
        return this.surcharge;
    }

    public void setSurcharge(double surcharge) {
        this.surcharge = surcharge;
    }

    public double discount() {
        return this.num * this.price * 5 / 100;
    }

    public void input() {
        super.input();
        Scanner zz = new Scanner(System.in);
        System.out.print("Enter surcharge: ");
        surcharge = zz.nextDouble();
    }

    public void output() {
        super.output();
        System.out.println("   surcharge: " + this.surcharge);
    }
}

class TVLIST {
    TV[] a = new TV[100];
    int n = 0;
    char chon, loai;

    void inputtv() throws IOException {
      
        do {
            System.out.print("Samsung or Sony (S/N): ");
            chon = (char)System.in.read();
            if (chon == 's' || chon == 'S') {
                a[n] = new TV_SAMSUNG();
            } else {
                a[n] = new TV_SONY();
            }
            System.in.read();
            a[n++].input();
            System.out.print("Continue (C/K): ");
            loai =(char)System.in.read();
            System.in.skip(loai);
            if (n == 100 || loai == 'K' || loai == 'k') {
                break;
            }
        } while (true);
    }

    void outputtv() {
        for (int i = 0; i < n; i++) {
            a[i].output();
        }
    }
    
    void add(TV tv) {
        if (n < 100) {
            a[n++] = tv;
        } else {
            System.out.println("Danh sach da day, khong the them phan tu moi!");
        }
    }
    
    void sort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].sumTotal() > a[j].sumTotal()) {
                    TV temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        System.out.println("Sau khi sap xep: ");
        for (int i = 0; i < n; i++) {
            a[i].output();
        }
    }

    void sum() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i].sumTotal();
        }
        System.out.println("Tong gia tri: " + sum);
    }

    void delete() {
        Scanner tt = new Scanner(System.in);
        System.out.print("Nhap vi tri phan tu ban muon xoa: ");
        int d = tt.nextInt();
        if (d >= 0 && d < n) {
            for (int i = d; i < n - 1; i++) {
                a[i] = a[i + 1];
            }
            n--;
        } else {
            System.out.println("Vi tri khong hop le!");
        }
    }

  
}

public class Tv {
    public static void main(String[] args) throws IOException {
        TVLIST z = new TVLIST();
        
        z.inputtv();
        z.outputtv();
        TV_SAMSUNG newTV = new TV_SAMSUNG("TV123", "Samsung", "2024-09-13", 500.0, 2, "new");
        z.add(newTV);
        z.outputtv();
        z.sort();
        z.sum();
        z.delete();

       
    }
}
