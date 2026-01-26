
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list=new ArrayList<>();
        if(root==null)return list;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
            int len=queue.size();
            List<Integer>cur=new ArrayList<>();
            for(int i=0;i<len;i++){
                TreeNode curNode=queue.poll();
                cur.add(curNode.val);
                if(curNode.left!=null)queue.offer(curNode.left);
                if(curNode.right!=null)queue.offer(curNode.right);
            }
            list.add(cur);
        }
        return list;
    }
}