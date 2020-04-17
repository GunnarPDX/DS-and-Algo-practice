
def is_valid_bst(root, min = -1.0/0.0, max = 1.0/0.0)
    return true if root.nil?
    return false if min >= root.val || max <= root.val
    return false if (!root.left.nil? && (root.val <= root.left.val)) || (!root.right.nil? && (root.val >= root.right.val))
    return is_valid_bst(root.left, min, root.val) && is_valid_bst(root.right, root.val, max)
end

