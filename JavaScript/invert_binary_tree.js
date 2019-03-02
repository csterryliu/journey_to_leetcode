// Definition for a binary tree node.
// function TreeNode(val) {
//     this.val = val;
//     this.left = this.right = null;
// }
class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

var invertTree = function(root) {
    dfs(root);
    return root;
}

function dfs(root) {
    if (!root) {
        return;
    }
    if (root.right || root.left) {
        const temp = root.left;
        root.left = root.right;
        root.right = temp;
    }
    dfs(root.right);
    dfs(root.left);
    return;
}

let tree = new TreeNode(4);
tree.left = new TreeNode(2);
tree.left.left = new TreeNode(1);
tree.left.right = new TreeNode(3);
tree.right = new TreeNode(7);
tree.right.left = new TreeNode(6);
tree.right.right = new TreeNode(9);



invertTree(tree);

console.log(tree);