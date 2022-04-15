package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println("Project test 3 by IJ");
        int value = JnaDLL.jnadll.add(1,2);
        int flag = JnaDLL.jnadll.test_matrix(1.5,1.5);
        System.out.println("flag = "+flag);
        System.out.println("value = "+value);
        JnaDLL.jnadll.test_qpOASES();
    }
}
