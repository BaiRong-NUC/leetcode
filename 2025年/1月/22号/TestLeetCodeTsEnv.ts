//测试TS LeetCode刷题环境
import { TreeNode, ListNode, PrintCur } from "../../../global/global";

//构建树
function buildTree(arr: number[]): TreeNode | null {
    if (arr.length === 0) {
        return null;
    }
    const root = new TreeNode(arr[0]);
    const queue: TreeNode[] = [root];
    let i = 1;
    while (i < arr.length) {
        const node = queue.shift();
        if (node !== undefined) {
            if (arr[i] !== null) {
                node.left = new TreeNode(arr[i]);
                queue.push(node.left);
            }
            i++;
            if (i < arr.length && arr[i] !== null) {
                node.right = new TreeNode(arr[i]);
                queue.push(node.right);
            }
            i++;
        }
    }
    return root;
}

let print: PrintCur = new PrintCur();
print.printTree(buildTree([1, 2, 3, 4, 5, 6, 7]));