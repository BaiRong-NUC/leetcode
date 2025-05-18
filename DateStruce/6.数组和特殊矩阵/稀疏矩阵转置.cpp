#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
typedef int ElemType;
// 稀疏矩阵元素,三元组
typedef struct SparseMatrixNode
{
    int row;
    int col;
    ElemType value;
} SparseMatrixNode;
// 稀疏矩阵
typedef struct SparseMatrix
{
    vector<SparseMatrixNode> matrix;
    int rows;
    int cols;
} SparseMatrix;

// 方法一:普通转置算法,每次遍历找这次转置需要的元素
SparseMatrix transSparseMatrix(SparseMatrix &srcMatrix)
{
    SparseMatrix retMatrix;
    retMatrix.rows = srcMatrix.cols;
    retMatrix.cols = srcMatrix.rows;
    if (srcMatrix.matrix.size() > 0)
    {
        for (int i = 0; i < retMatrix.rows; i++)
        {
            // 遍历原矩阵的每个非零元素
            for (int j = 0; j < srcMatrix.matrix.size(); j++)
            {
                if (srcMatrix.matrix[j].col == i)
                {
                    // 找到srcMatrix.matrix[j]元素转置要放的位置
                    // 构造新的三元组
                    SparseMatrixNode newNode;
                    newNode.row = srcMatrix.matrix[j].col;
                    newNode.col = srcMatrix.matrix[j].row;
                    newNode.value = srcMatrix.matrix[j].value;
                    retMatrix.matrix.push_back(newNode);
                }
            }
        }
    }
    return retMatrix;
}

// 方法二:快速转置,转置前先计算每个非零元素转置后的位置再开始转置
SparseMatrix transSparseMatrixFast(SparseMatrix &srcMatrix)
{
    SparseMatrix retMatrix;
    retMatrix.rows = srcMatrix.cols;
    retMatrix.cols = srcMatrix.rows;
    retMatrix.matrix.resize(srcMatrix.matrix.size());
    if (srcMatrix.matrix.size() > 0)
    {
        // 有转置的元素
        vector<int> colBeginPos(srcMatrix.cols, 0);   // 记录每一列的起始位置
        vector<int> colNodeNumebr(srcMatrix.cols, 0); // 记录每列元素个数
        // 计算每列的非零元素个数
        for (int i = 0; i < srcMatrix.matrix.size(); i++)
        {
            // 对应列的元素+1
            colNodeNumebr[srcMatrix.matrix[i].col] += 1;
        }
        // 计算每列元素的起始位置
        /**
         * 第一列的起始位置总是0
         * 后续列的起始位置等于前一列的起始位置加上前一列的非零元素个数
         */
        for (int i = 1; i < srcMatrix.cols; i++)
        {
            colBeginPos[i] = colBeginPos[i - 1] + colNodeNumebr[i - 1];
        }
        // 开始转置
        for (int i = 0; i < srcMatrix.matrix.size(); i++)
        {
            int pos = colBeginPos[srcMatrix.matrix[i].col]; // 找到srcMatrix.matrix[i]元素转置要放的位置
            colBeginPos[srcMatrix.matrix[i].col] += 1;      // 对应列的起始位置+1
            retMatrix.matrix[pos].row = srcMatrix.matrix[i].col;
            retMatrix.matrix[pos].col = srcMatrix.matrix[i].row;
            retMatrix.matrix[pos].value = srcMatrix.matrix[i].value;
        }
    }
    return retMatrix;
}
/**
    普通转置和快速转置是稀疏矩阵转置的两种主要算法，它们的主要区别如下：
        1. 时间复杂度:
            - 普通转置：O(cols * terms_cnt)
            - 快速转置：O(cols + terms_cnt)
        2. 空间复杂度:
            - 普通转置：O(1) 额外空间
            - 快速转置：O(cols) 额外空间（用于存储每列的非零元素个数和起始位置）
        3. 算法思想:
            - 普通转置:
                - 按列顺序遍历原矩阵
                - 对每列，扫描所有非零元素，找到属于该列的元素进行转置
            - 快速转置:
                - 先统计每列的非零元素个数
                - 计算每列在转置矩阵中的起始位置
                - 一次遍历即可完成转置
        4. 性能:
            - 当非零元素较多时，快速转置明显更快
            - 当非零元素很少时，两种算法性能差异不大
        5. 实现复杂度:
            - 普通转置实现简单直接
            - 快速转置需要额外的预处理步骤
        6. 适用场景:
            - 普通转置适合小规模矩阵或非零元素非常稀疏的情况
            - 快速转置适合大规模矩阵或非零元素较多的情况
    在实际应用中，通常优先选择快速转置算法，因为它在大规模数据处理时性能优势明显。但在某些特殊情况下（如矩阵非常稀疏或内存受限），普通转置可能更合适。
 */
// 打印稀疏矩阵
void printSparseMatrix(SparseMatrix &sparseMatrix)
{
    cout << "Row\tCol\tValue" << endl;
    for (int i = 0; i < sparseMatrix.matrix.size(); i++)
    {
        cout << sparseMatrix.matrix[i].row << "\t" << sparseMatrix.matrix[i].col << "\t" << sparseMatrix.matrix[i].value << endl;
    }
}

// 根据矩阵生成稀疏矩阵
SparseMatrix trueSparseMatrix(vector<vector<int>> &matrix)
{
    SparseMatrix sparseMatrix;
    if (matrix.size() == 0)
        return sparseMatrix;
    sparseMatrix.rows = matrix.size();
    sparseMatrix.cols = matrix[0].size();
    for (int i = 0; i < sparseMatrix.rows; i++)
    {
        for (int j = 0; j < sparseMatrix.cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                SparseMatrixNode node;
                node.row = i;
                node.col = j;
                node.value = matrix[i][j];
                sparseMatrix.matrix.push_back(node);
            }
        }
    }
    return sparseMatrix;
}

int main(int argc, char const *argv[])
{
    cout << "before trans SparseMatrix:\n";
    vector<vector<int>> matrix = {{2, 0, 6, 0}, {0, 0, 25, 0}, {0, 8, 0, 16}};
    SparseMatrix srcMatrix = trueSparseMatrix(matrix);
    printSparseMatrix(srcMatrix);
    SparseMatrix retMatrix = transSparseMatrix(srcMatrix);
    cout << "after trans SparseMatrix:\n";
    printSparseMatrix(retMatrix);
    SparseMatrix retMatrixFast = transSparseMatrixFast(srcMatrix);
    cout << "after trans SparseMatrixFast:\n";
    printSparseMatrix(retMatrixFast);
    return 0;
}
