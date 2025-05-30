# Solider - 2D动作游戏

一个使用C++和EasyX图形库开发的2D横版动作游戏，武士零和黄蜂女的战斗。

## 🎮 游戏特性

### 核心玩法

- **流畅的角色控制** - 支持移动、跳跃、翻滚和攻击
- **多方向攻击系统** - 上、下、左、右四个方向的攻击动作
- **敌人AI系统** - 智能敌人行为和状态机
- **碰撞检测** - 精确的碰撞检测和物理反馈
- **生命值系统** - 玩家和敌人的血量管理
- **子弹时间** - 特殊的时间缓慢效果

### 视觉效果

- **精美的像素艺术** - 手绘风格的角色和场景
- **流畅的动画系统** - 角色动作和特效动画
- **屏幕震动效果** - 战斗时的视觉反馈
- **UI界面** - 血量显示和游戏状态界面

## 🛠️ 技术栈

- **编程语言**: C++
- **图形库**: EasyX
- **开发环境**: Visual Studio 2022
- **平台**: Windows

## 📁 项目结构

```
Solider/
├── Solider/                    # 主要源代码目录
│   ├── main.cpp               # 程序入口点
│   ├── player.h/.cpp          # 玩家角色类
│   ├── enemy.h/.cpp           # 敌人角色类
│   ├── character.h/.cpp       # 角色基类
│   ├── animation.h            # 动画系统
│   ├── collision_manager.h/.cpp # 碰撞检测管理器
│   ├── resources_manager.h/.cpp # 资源管理器
│   ├── state_machine.h/.cpp   # 状态机系统
│   ├── bullet_time_manager.h/.cpp # 子弹时间管理器
│   ├── camera.h               # 摄像机系统
│   ├── timer.h                # 计时器工具
│   ├── util.h                 # 工具函数
│   ├── vector2.h              # 2D向量类
│   └── resources/             # 游戏资源文件
│       ├── player/            # 玩家角色资源
│       ├── enemy/             # 敌人角色资源
│       ├── audio/             # 音频文件
│       ├── background.png     # 背景图片
│       └── ui_heart.png       # UI心形图标
├── Solider.sln               # Visual Studio解决方案文件
└── README.md                 # 项目说明文档
```

## 🎯 核心系统

### 角色系统

- **Character基类** - 所有角色的基础类，包含位置、动画、碰撞等基本功能
- **Player类** - 玩家角色，支持键盘输入控制和多种动作
- **Enemy类** - 敌人角色，具有AI行为和攻击模式

### 状态机系统

- **StateMachine** - 管理角色的不同状态转换
- **StateNode** - 状态节点基类
- 支持玩家和敌人的复杂行为状态管理

### 动画系统

- **Animation类** - 处理精灵动画播放
- **Atlas类** - 管理精灵图集
- 支持循环播放和单次播放模式

### 碰撞检测

- **CollisionManager** - 统一管理所有碰撞检测
- **CollisionBox** - 碰撞盒组件
- 支持不同碰撞层级和类型

## 🎮 操作说明

- **移动**: A/D键 或 左/右方向键
- **跳跃**: W键 或 上方向键
- **翻滚**: Shift键
- **攻击**: J键
- **攻击方向**: 使用方向键控制攻击方向

## 🚀 编译和运行

### 环境要求

- Windows 10/11
- Visual Studio 2019 或更高版本
- EasyX图形库

### 编译步骤

1. 克隆或下载项目到本地

```bash
git clone https://github.com/KBchulan/Solider.git
cd Solider
```

2. 安装EasyX图形库

   - 下载并安装EasyX图形库
   - 确保库文件正确配置到Visual Studio
3. 打开解决方案

   - 使用Visual Studio打开 `Solider.sln`
4. 编译项目

   - 选择Debug或Release配置
   - 选择x86或x64平台
   - 按F5运行或Ctrl+F5编译

### 运行要求

- 确保resources目录下的所有资源文件完整
- 音频文件需要系统支持相应的音频格式
