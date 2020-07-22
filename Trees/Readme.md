https://leetcode.com/problems/delete-node-in-a-bst/

Cases to consider:

        1. Node has no children. Simply remove it
        
        2. Node has one child. Replace node with child's subtree
        
        3. Node has two children. Find minimum value in right subtree and replace it with current node to delete
        
      
