package com.company;

import java.util.EmptyStackException;

/**
 * Created by manfred on 11/15/2015.
 */
public class KthSmallestInBST {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public static void main(String[] args) {
        KthSmallestInBST k = new KthSmallestInBST();
    }

    public KthSmallestInBST() {
        TreeNode root = new TreeNode(6);
        root.left = new TreeNode(2);
        root.right = new TreeNode(8);
        root.right.left = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(4);
        root.left.right.left = new TreeNode(3);
        root.left.right.right = new TreeNode(5);

        System.out.println(kthSmallest(root, 4));
    }

    private int count;
    private int target;
    private int kthVal;

    public int kthSmallest(TreeNode root, int k) {
        count = 0;
        target = k;

        try{
            infix(root);
        }
        catch (Exception e){
            return kthVal;
        }

        return -1;
    }

    private void infix(TreeNode node) throws Exception{
        if(node.left != null)
            infix(node.left);

        count++;
        if(count == target){
            kthVal = node.val;
            throw new Exception();
        }

        if(node.right != null)
            infix(node.right);
    }
}
