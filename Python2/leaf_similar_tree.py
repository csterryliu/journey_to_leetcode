def leafSimilar(self, root1, root2):
  output1 = []
  output2 = []
  dfs_postorder(root1, output1)
  dfs_postorder(root2, output2)
  return output1 == output2
  
  
def dfs_postorder(root, output):
    if not root:
    	return True
    is_left_empty = dfs_postorder(root.left, output)
    is_right_empty = dfs_postorder(root.right, output)
    if is_left_empty and is_right_empty:
        output.append(root.val)
    return False
