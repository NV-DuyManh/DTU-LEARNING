package ghivaofile;

import java.util.*;
import java.io.*;

class fileIO {

	void input() throws IOException {
		File fo = new File("D:\\bai2.txt");
		FileWriter fw = new FileWriter(fo);
		try {
			fw.write("1. Mạnh prolayer\n");
			fw.write("2. Hiếu tạ");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			fw.close();
		}
		fw.close();
	}

	void output() throws IOException {
		File fi = new File("D:\\bai2.txt");
		FileReader fr = new FileReader(fi);
		BufferedReader br = new BufferedReader(fr);
		String str;
		try {
			while ((str = br.readLine()) != null) {
				System.out.println(str);
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
			br.close();
		}
		br.close();
	}

}

public class bai2 {

	public static void main(String[] args) throws IOException {
		fileIO st = new fileIO();
		st.input();
		st.output();
	}
}
