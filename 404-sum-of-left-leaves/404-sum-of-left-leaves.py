
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        
        if not root:
            return 0
        
        def travel(node, flag):
            if not node:
                return 0

            if (flag and not node.left and not node.right):
                    return node.val

            return travel(node.left, True) + travel(node.right, False)
        
        return travel(root,False)
