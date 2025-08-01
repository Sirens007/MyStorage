## 以自己经验用Git
### Git基础概念
Git = word写文档	GitHub = 腾讯文档分享协作

Git三个区域

```git
工作区（Working Directory）—— 你正在编辑的文件
  ↓ git add
暂存区（Staging Area）—— 即将提交的快照
  ↓ git commit
版本库（Repository）—— Git 保存的历史记录
```

完整的开发流程通常是：

```git
# 修改代码
git add 文件名             # 添加文件到暂存区
git commit -m "说明信息"   # 提交暂存区到版本库
```

---

### 本地 Git 仓库操作
以下内容是指在终端中使用

```git
git config --global user.name "待填入名字"
git config -- global user.email "待填入邮箱"	#建议使用注册GitHub的用户名和邮箱，便于同步
                                  # --global 表示在你这台电脑上的所有仓库都使用这套设置。

git init #建立Git仓库，初始化Git仓库
         #或者从GitHub上拉一个项目（如刚创建了远程仓库）
git clone https://github.com/Sirens007/MyStorage.git

#如创建一个新文件
echo "#我的第一个项目" > README.md
#添加到Git暂存区
git add README.md
#提交到本地仓库
git commit -m "添加了README文件"
#绑定 GitHub 仓库作为远程仓库 origin	（即origin为远程仓库昵称）
git remote add origin https://github.com/Sirens007/MyStorage.git
#首次推送GitHub
git push -u origin main #如果提示 main 不存在，可以先用 git branch -M main 把默认的 master 分支改名。

git status
#查看当前工作状态 （如查看还未暂存的文件
git log
#查看提交历史

```

---

### 查看状态与差异
当你已经完成了基本的 `add` 和 `commit` 操作后，日常开发中你最常用的两个命令是：

+ `git status`：查看当前仓库状态
+ `git diff`：查看文件内容发生了哪些改动

**一、git status —— 查看状态**

```git
git status
```

** 作用：**

查看当前工作区和暂存区的状态。

** 原理解释：**

Git 会比较这三者的内容是否一致：

1. **工作目录中的文件**
2. **暂存区中的文件（通过 git add 添加的）**
3. **最后一次提交的版本（历史）**



## Git工作流程
![](https://cdn.nlark.com/yuque/0/2025/png/49819380/1752228604355-40300e5a-f863-468c-92e6-de44d1592207.png)

### 1.克隆仓库
如果你要参与一个已有的项目，通常会创建一个新的分支：

```git
git clone https://github.com/username/repo.git
cd repo
```

### 2.创建新分支
为了避免直接在main或master分支上进行开发，通常会创建一个新的分支：

```git
git checkout -b new-feature
```

### 3.工作目录
在工作目录中进行代码编辑、添加新文件或删除不需要的文件。

### 4.暂存文件
将修改的文件添加到暂存区，以便进行下一步的提交操作：

```git
git add filename
# 或者添加所有修改的文件
git add .
```

### 5.提交更改
将暂存区的更改提交到本地仓库，并添加提交信息：

```git
git commit -m "Add new feature"
```

### 6.拉取最新更改
推送本地更改之前，最好从远程仓库拉取最新的更改，以避免冲突：

```git
git pull origin main
# 或者如果在新的分支上工作
git pull origin new-feature
```

### 7.推送更改
将本地的提交推送到远程仓库：

```git
git push origin new-feature
```

### 8.创建Pull Request（PR）
在github或其他托管平台上创建Pull Request，邀请团队成员进行代码审查。PR合并后，你的更改就会合并到主分支。

### 9.合并更改
在PR审核通过并合并后，可以将远程仓库的主分支合并到本地分支：

```git
git checkout main
git pull origin main
git merge new-feature
```

### 10.删除分支
如果不需要新功能分支，可以将其删除：

```git
git branch -d new-feature
```

或者从远程仓库删除分支：

```git
git push origin --delete new-feature
```

## Git创建仓库
### git init
Git使用git init命令来初始化一个Git仓库，Git的很多命令都需要在Git的仓库中运行，所以git init是使用Git的第一个命令。

在执行完git init命令后，Git仓库会生成一个.git目录，该目录包含了资源的所有元数据，其他的项目目录保持不变。

**使用方法**

进入想要创建仓库的目录，或者先创建一个新的目录：

```git
mkdir my-project
cd my-project
```

使用当前目录作为Git仓库，我们只需使用它初始化。

```git
git init
```

该命令执行完成后会在当前目录生成一个.git目录。

使用我们指定目录作为Git仓库。

```git
git init newrepo
```

初始化后，会在newrepo目录下会出现一个名为.git的目录，所有Git需要的数据和资源都存放在这个目录中。

如果当前目录下有几个文件想要纳入版本控制，需要先使用git add 命令告诉Git开始对这些文件进行跟踪，然后提交：

```git
git add *.c 	 #将所有.c文件纳入版本控制
git add README #添加README文件（一般为项目说明文档），可以是README.md、README.txt
git commit -m '初始化项目版本'  #
```

以上命令将目录一下以 .c 结尾及README文件提交到仓库中。

> **注：**在Linux系统中，commit信息使用单引号 ' ，Windows系统，commit信息使用双引号"。
>
> 所以在git bash中 git commit -m '提交说明' 这样是可以的，在Windows命令行中就要使用双引号 git commit -m "提交说明"。
>

### git clone
我们使用git clone 从现有的Git仓库中拷贝项目（类似svn checkout）。

克隆仓库的命名格式为：

```git
git clone <repo>
```

如果我们需要克隆到指定的目录，可以使用以下命令格式：

```git
git clone <repo> <directory>
```

参数说明：

+ repo:Git仓库
+ directory:本地仓库

比如，要克隆Ruby语言的Git代码仓库Grit，可以用下面的命令：

```git
git clone git://github.com/Sirens007/MyStorage.git Mystorage
#git:为Git专属协议，类似https

#git clone git://github.com/Sirens007/MyStorage.git 是仓库地址，指向Github上名为MyStorage的仓库
```

**配置**

git的设置使用 git config 命令

显示当前的git配置信息：

```git
$ git config --list
#输出以下信息
credential.helper=osxkeychain
core.repositoryformatversion=0
core.filemode=true
core.bare=false
core.logallrefupdates=true
core.ignorecase=true
core.precomposeunicode=true
```

编辑git配置文件：

```git
git config -e	#针对当前仓库
```

或者：

```git
git config -e --global	#针对系统上所有仓库
```

设置提交代码时的用户信息：

```git
git config --global user.name "Sirens007"
git config --global user.email "2921646312@qq.com"
```

如果去掉 --global参数支队当前仓库有效。

## Git基本操作
<font style="color:rgb(51, 51, 51);">Git 的工作就是创建和保存你项目的快照及与之后的快照进行对比。</font>

<font style="color:rgb(51, 51, 51);">本章将对有关创建与提交你的项目快照的命令作介绍。</font>

<font style="color:rgb(51, 51, 51);">Git常用的是以下6个命令：git clone、git push、git add、git commit、git checkout、git pull，之后会详细介绍</font>

![](https://cdn.nlark.com/yuque/0/2025/jpeg/49819380/1752793978832-10a3a622-cb2a-44d6-8e0e-905e3538f607.jpeg)

说明：

+ workplace：工作区
+ staging area：暂存区/缓存区
+ local repository：版本库或本地仓库
+ remote  respository：远程仓库

一个简单的操作步骤：

```git
git init
git add
git commit
```

+ git init - 初始化仓库。
+ git add - 添加文件到暂存区。
+ git commit - 将暂存区内容添加到仓库中。

**创建仓库命令**

git创建仓库的命令：



| 命令 | 说明 | |
| --- | --- | --- |
| git init | 初始化仓库 | |
| git clone | 拷贝一份远程仓库，也就是下载一个项目 | |


### 提交与修改
Git的工作就是创建和保存你的项目的快照及与之后的快照进行对比。

下表列出有关创建与提交你的项目的快照的命令：

| 命令 | 说明 |
| --- | --- |
| git add | 添加文件到暂存区 |
| git status | 查看仓库当前的状态，显示有变更的文件 |
| git diff | 比较文件的不同，即暂存区和工作区的差异 |
| git difftool | 使用外部差异工具查看和比较文件的更改 |
| git range-diff | 比较两个提交范围之间的差异 |
| git commit | 提交暂存区到本地仓库 |
| git reset | 回退版本 |
| git rm | 将文件从暂存区和工作区中删除 |
| git mv | 移动或重命名工作区文件 |
| git notes | 添加注释 |
| git checkout | 分支切换 |
| git switch（Git 2.23版本） | 更清晰地切换分支 |
| git restore（Git 2.23版本） | 恢复或撤销文件的更改 |
| git show | 显示Git对象的详细信息 |


**提交日志**

| 命令 | 说明 |
| --- | --- |
| git log | 查看历史提交记录 |
| git blame <file> | 以列表形式查看指定文件的历史修改记录 |
| git shortlog | 生成简洁的提交日志摘要 |
| git describe | 生成一个可读的字符串，该字符串基于Git的标签系统来描述当前的提交 |


**远程操作**

| 命令 | 说明 |
| --- | --- |
| git remote | 远程仓库操作 |
| git fetch | 从远程获取代码库 |
| git pull | 下载远程代码并合并 |
| git push | 上传远程代码并合并 |
| git submodule | 管理包含其他Git仓库的项目 |


### Git文件状态
Git的文件状态分为三种：工作目录（Working Directory）、暂存区（Staging Area）、本地仓库（Local Repository）。

**工作目录（Working Directory）**

工作目录是你在本地计算机上看到的项目文件。它是你实际操作文件的地方，包括查看、编辑、删除和创建文件。所有对文件的更改首先发生在工作目录中。

在工作目录中的文件可能有以下几种状态：

+ 未跟踪（Untracked）：新创建的文件，未被Git记录。
+ 已修改（Modified）：已被Git跟踪的文件发生了更改，但这些更改还没有被提交到Git记录中。

**暂存区（Staging Area）**

 暂存区，也被称为索引（Index），是一个临时存储区域，用于保存即将提交到本地仓库的更改。你可以选择性地将工作目录中的更改添加到暂存区中，这样你就可以一次提交多个文件的更改，而不必提交所有文件的更改。

+ 使用git add <filename> 命令将文件从工作目录添加到暂存区。
+ 使用git add . 命令将当前目录下的所有更改添加到暂存区。

> git add <filename>   # 添加指定文件到暂存区
>
> git add .           	  # 添加所有更改到暂存区
>

**本地仓库（Local Respository）**

本地仓库是一个隐藏在 .git 目录中的数据库，用于存储项目的所有提交历史记录。每次你提交更改时，Git会将暂存区中的内容保存到本地仓库中。

使用 git commit -m "commit message" 命令将暂存区中的更改提交到本地仓库。

> git commit -m "commit message"   # 提交暂存区的更改到本地仓库
>

**文件状态的转换流程**

**未跟踪（Untracked）：**新创建的文件最初是未跟踪的。它们存在于工作目录中，但没有被Git跟踪。

> git add newfile.txt  # 添加文件到暂存区
>
> git status           # 查看状态，显示 newfile.txt 在暂存区
>

**已跟踪（Tracked）：**通过git add 命令将未跟踪的文件添加到暂存区后，文件变为已跟踪状态。

