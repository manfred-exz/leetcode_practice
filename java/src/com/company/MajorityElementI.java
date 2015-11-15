package com.company;

/**
 * Created by manfred on 11/15/2015.
 * O(n) time, and O(1) space
 */
public class MajorityElementI {

    public int majorityElement(int[] nums) {
        int result = nums[0];
        int len = nums.length;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (count == 0 || result == nums[i]) {
                result = nums[i];
                count++;
            } else
                count--;
        }
        return result;
    }

    public MajorityElementI() {
        int testCase[] = {1, 2, 3, 3, 3, 3, 2,};

        System.out.println(majorityElement(testCase));
    }

    public static void main(String[] args) {
        MajorityElementI m = new MajorityElementI();
    }
}
