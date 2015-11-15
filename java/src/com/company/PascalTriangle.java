package com.company;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by manfred on 11/4/2015.
 * not default
 */
public class PascalTriangle {
    public static void main(String[] args){
        List<Integer> result = getRow(1);

        result.forEach(System.out::println);
    }

    public static List<Integer> getRow(int rowIndex) {
        List<Integer> listA = new ArrayList<>(rowIndex), listB = new ArrayList<>(rowIndex);

        listA.add(0, 1);
        if(rowIndex == 0)
            return listA;

        List<Integer> previousList = listA;
        List<Integer> currentList = listB;
        List<Integer> tmpList;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                int preA, preB;
                preA = j - 1 < 0 ? 0 : previousList.get(j - 1);
                preB = j == i ? 0 : previousList.get(j);
                currentList.add(j, preA + preB);
            }

            tmpList = currentList;
            currentList = previousList;
            previousList = tmpList;

            currentList.clear();
        }

        return previousList;
    }
}