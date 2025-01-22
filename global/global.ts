// 定义TreeNode结构
export class TreeNode {
    val: number;
    left: TreeNode | null;
    right: TreeNode | null;

    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
    }
}

// 定义ListNode结构
export class ListNode {
    val: number;
    next: ListNode | null;

    constructor(val?: number, next?: ListNode | null) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
}

// 二叉树打印函数方便测试
export class PrintCur {
    // 计算二叉树深度
    deep(root: TreeNode | null): number {
        if (root === null) {
            return 0;
        }
        const left = this.deep(root.left);
        const right = this.deep(root.right);
        return Math.max(left, right) + 1;
    }

    // 深度优先搜索打印二叉树
    dfs(root: TreeNode | null, ret: string[][], row: number, col: number, deep: number): void {
        if (root === null) {
            return;
        }
        ret[row][col] = root.val.toString();
        if (root.left !== null) {
            this.dfs(root.left, ret, row + 1, col - (1 << (deep - row - 1)), deep);
        }
        if (root.right !== null) {
            this.dfs(root.right, ret, row + 1, col + (1 << (deep - row - 1)), deep);
        }
    }

    // 打印二叉树
    printTree(root: TreeNode | null): string[][] {
        const treeDeep = this.deep(root) - 1; // 根节点高度为0
        const row = treeDeep + 1;
        const col = (1 << row) - 1;
        const ret: string[][] = new Array(row).fill(null).map(() => new Array(col).fill(""));
        this.dfs(root, ret, 0, (col - 1) / 2, treeDeep);
        for (let i = 0; i < ret.length; i++) {
            for (let j = 0; j < ret[i].length; j++) {
                console.log(ret[i][j] + " ", { end: '' });
            }
            console.log("\n", { end: '' });
        }
        return ret;
    }

    // 打印一维数组
    printVecter(buff: number[]): void {
        for (const num of buff) {
            console.log(num + " ", { end: '' });
        }
        console.log("\n", { end: '' });
    }

    // 打印二维数组
    printVecterDouble(buff: number[][]): void {
        for (const num of buff) {
            this.printVecter(num);
        }
    }

    // 打印链表
    printList(head: ListNode | null): void {
        while (head !== null) {
            console.log(head.val + " ", { end: '' });
            head = head.next;
        }
        console.log("\n", { end: '' });
    }
}