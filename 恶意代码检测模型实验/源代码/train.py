# train.py

import os
import numpy as np
import lightgbm as lgb
from sklearn.metrics import roc_auc_score, confusion_matrix, classification_report, roc_curve, auc
import matplotlib.pyplot as plt
import seaborn as sns


def load_data(data_dir):
    """
    加载训练和测试数据。
    """
    processed_dir = os.path.join(data_dir, 'processed')
    X_train = np.load(os.path.join(processed_dir, 'X_train.npy'))
    y_train = np.load(os.path.join(processed_dir, 'y_train.npy'))
    X_test = np.load(os.path.join(processed_dir, 'X_test.npy'))
    y_test = np.load(os.path.join(processed_dir, 'y_test.npy'))
    return X_train, y_train, X_test, y_test


def train_lightgbm(X_train, y_train):
    """
    使用 LightGBM 训练模型。
    """
    print("开始训练 LightGBM 模型...")
    params = {
        'objective': 'binary',
        'boosting_type': 'gbdt',
        'learning_rate': 0.05,
        'num_leaves': 31,
        'n_estimators': 200,
        'random_state': 42
    }

    model = lgb.LGBMClassifier(**params)
    model.fit(X_train, y_train)
    print("LightGBM 模型训练完成。\n")
    return model


def evaluate_model(model, X_test, y_test, save_dir):
    """
    评估模型性能并保存图表。
    """
    print("开始评估模型性能...")
    y_pred_proba = model.predict_proba(X_test)[:, 1]
    y_pred = (y_pred_proba >= 0.5).astype(int)

    roc_auc = roc_auc_score(y_test, y_pred_proba)
    print(f"ROC AUC: {roc_auc:.4f}")

    cm = confusion_matrix(y_test, y_pred)
    print("混淆矩阵：")
    print(cm)

    cr = classification_report(y_test, y_pred, target_names=['Benign', 'Malicious'])
    print("分类报告：")
    print(cr)

    # 绘制 ROC 曲线
    fpr, tpr, thresholds = roc_curve(y_test, y_pred_proba)
    plt.figure(figsize=(8, 6))
    plt.plot(fpr, tpr, color='darkorange', lw=2, label=f'ROC curve (area = {roc_auc:.4f})')
    plt.plot([0, 1], [0, 1], color='navy', lw=2, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('Receiver Operating Characteristic (ROC) Curve')
    plt.legend(loc="lower right")
    plt.grid(True)
    os.makedirs(os.path.join(save_dir, 'figures'), exist_ok=True)
    plt.savefig(os.path.join(save_dir, 'figures', 'roc_curve.png'))
    plt.show()

    # 绘制预测分数分布
    plt.figure(figsize=(8, 6))
    sns.histplot(y_pred_proba[y_test == 0], bins=50, color='blue', label='Benign', stat='density', kde=True, alpha=0.6)
    sns.histplot(y_pred_proba[y_test == 1], bins=50, color='red', label='Malicious', stat='density', kde=True, alpha=0.6)
    plt.xlabel('Prediction Score')
    plt.ylabel('Density')
    plt.title('Prediction Score Distribution')
    plt.legend()
    plt.savefig(os.path.join(save_dir, 'figures', 'score_distribution.png'))
    plt.show()

    print("模型评估完成。\n")


def main():
    # 数据目录
    data_dir = "data"  # 根据实际路径调整

    # 加载数据
    print("加载数据...")
    X_train, y_train, X_test, y_test = load_data(data_dir)
    print("数据加载完成。\n")

    # 训练模型
    model = train_lightgbm(X_train, y_train)

    # 保存模型
    os.makedirs('models', exist_ok=True)
    model.booster_.save_model('models/lgbm_model.txt')
    print("模型已保存至 models/lgbm_model.txt\n")

    # 评估模型
    evaluate_model(model, X_test, y_test, 'reports')


if __name__ == "__main__":
    main()
