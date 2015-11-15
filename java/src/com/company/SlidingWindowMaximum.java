package com.company;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by manfred on 11/4/2015.
 * not default
 */
public class SlidingWindowMaximum {
    public static void main(String[] args) {
        int[] nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int[] res = maxSlidingWindow(nums, 3);

        for (int re : res) {
            System.out.print(re + " ");
        }
    }

    public static int[] maxSlidingWindow(int[] nums, int k) {
        List<Integer> res = new ArrayList<>();
        ArrayDeque<Integer> q = new ArrayDeque<>();


        for (int i = 0; i < nums.length; ++i) {
            if (!q.isEmpty() && q.getFirst() == i - k)
                q.removeFirst();

            while (!q.isEmpty() && nums[q.getLast()] < nums[i])
                q.removeLast();

            q.addLast(i);
            if (i >= k - 1)
                res.add(nums[q.getFirst()]);

//            System.out.print("Current queue: ");
//            for (Integer idx : q) {
//                System.out.print(nums[idx] + " ");
//            }
//            System.out.println();
        }

        int[] _res = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            _res[i] = res.get(i);
        }

        return _res;
    }
}
