## 以自己经验用Git
### 1.Git基础概念
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

### 2.本地 Git 仓库操作
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

### 3.查看状态与差异
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

<details class="lake-collapse"><summary id="u29606243"><strong><span class="ne-text">结果分析</span></strong></summary><h4 id="98be1ecf"><span class="ne-text">情况1：工作区干净</span></h4><pre data-language="git" id="WQi54" class="ne-codeblock language-git"><code>$ git status
On branch master
nothing to commit, working tree clean</code></pre><p id="u0e2b9816" class="ne-p"><span class="ne-text">意思是：没有文件被修改，也没有新增或删除。</span></p><hr id="sfw3z" class="ne-hr"><h4 id="3e1a3f71"><span class="ne-text" style="color: #DF2A3F">🟡</span><span class="ne-text" style="color: #DF2A3F"> </span><span class="ne-text">情况2：修改了文件但还没 add</span></h4><pre data-language="git" id="ZGtno" class="ne-codeblock language-git"><code>$ git status
modified:   hello.txt</code></pre><p id="ufa272c14" class="ne-p"><span class="ne-text">说明 </span><code class="ne-code"><span class="ne-text">hello.txt</span></code><span class="ne-text"> 有改动，但还没有被添加进暂存区。</span></p><hr id="otrcG" class="ne-hr"><h4 id="c160fd94"><span class="ne-text">🟢</span><span class="ne-text"> 情况3：已 add 到暂存区但还没 commit</span></h4><pre data-language="git" id="L2q4R" class="ne-codeblock language-git"><code>$ git status
Changes to be committed:
  (use &quot;git restore --staged &lt;file&gt;...&quot; to unstage)
        modified:   hello.txt</code></pre></details>
**二、git diff —— 查看修改内容**

```git
git diff
```

** 作用：**

+ 显示当前工作目录中未加入暂存区的变更（对比的是：工作区 ↔ 暂存区）

---

**你也可以用：**

```git
git diff hello.txt
```

来查看某个具体文件的改动。

<details class="lake-collapse"><summary id="u423a2fc5"><strong><span class="ne-text">补充</span></strong></summary><h3 id="k8LQy"><span class="ne-text">查看已经 add 但还未 commit 的差异：</span></h3><pre data-language="git" id="J3Z0b" class="ne-codeblock language-git"><code>git diff --cached</code></pre><p id="u52bf5124" class="ne-p"><span class="ne-text">或者：</span></p><pre data-language="git" id="cEllX" class="ne-codeblock language-git"><code>git diff --staged</code></pre><h4 id="u539c"><span class="ne-text"></span><span class="ne-text">作用：</span></h4><ul class="ne-ul"><li id="udf0dfced" data-lake-index-type="0"><span class="ne-text">查看“暂存区”中与“上一次提交版本”之间的差异。</span></li></ul></details>
---

### 4.文件恢复与版本回退
**开发中你经常会遇到这些情况：**

| **场景** | **想做的事** |
| --- | --- |
| 改错文件了 | 想恢复回之前保存的版本 |
| add 错文件了 | 想撤回到未暂存状态 |
| commit 之后后悔了 | 想撤销或回退提交 |
| 改了很多但不想要了 | 想恢复整个文件夹到之前状 |


**本节主要命令：**

+ `git restore`：恢复文件内容（推荐）
+ `git checkout`：旧版本恢复（老派用法）
+ `git reset`：取消暂存、版本回退
+ `git log`：查看历史提交

---

** ****一、恢复工作区文件：**`**git restore**`

```git
git restore <filename>

eg:
echo "bad line" >> hello.txt      # 加了一行错误内容
git restore hello.txt             # 撤销这次改动
```

**作用**：

把某个文件恢复到上一次 `git add` 或 `git commit` 之后的状态，**取消你刚刚改的内容**。

**背后原理：**

从 Git 暂存区或仓库中拿出该文件的版本，覆盖当前工作区。

---

** 二、撤销 **`**git add**`**：**`**git restore --stage**d`

```git
git restore --staged <filename>

eg:
git add hello.txt
git restore --staged hello.txt  #撤回add，但改动还在
```

**作用：**

把文件从**暂存区**移除，但保留工作区的改动。

**使用场景：**

你 `git add` 了一个不该提交的文件，可以用这条命令撤回。

---

 **三、版本回退：**`**git reset**`

**命令：取消已经 add 的内容**

```git
git reset filename
```

等效于上面那句 `git restore --staged`，只是老一点的写法。

---

**命令：回退到上一个提交版本（慎用）**

```git
git reset --hard HEAD
```

**作用：**

把整个项目（工作区 + 暂存区）恢复到上一次提交的状态。

 ❗❗ 注意：`--hard` 是“硬回退”，**不可恢复的清空当前修改**，一定要确认再用！  

---

** 四、查看历史版本：**`**git log**`

+ 显示提交历史
+ 会看到一堆 `commit xxx...` 的 ID、作者、时间、提交说明

```git
git log

eg:
git log -p hello.txt	#查看历史内容改了什么
```

### 5.分支管理（分支的创建、切换、合并）
在实际开发中，我们经常会遇到这种需求：

+ 不打扰主线代码，先试试一个新功能
+ 多个开发人员各自写各自的功能
+ 想在多个版本之间切换工作

这时，就要用到「**分支（branch）**」来隔离、管理不同的开发线。

**Git 分支基本概念**

+ **主分支**：默认叫 `master`（或 `main`）
+ **分支的本质**：一个指向某次提交的“指针”
+ **HEAD**：指向当前分支的位置（你正在干活的分支）

**1.查看已有分支 **`**git branch 分支名**`

```git
git branch
```

+ 会列出当前所有分支，当前所在的分之前有`*`标记

---

**2.创建新分支：**`git branch 分支名`

```git
git branch dev
```

+ 创建一个名为dev的新分支，复制自当前分支的最新提交。

---

**3.切换分支：**`git switch 分支名`

```git
git switch dev
```

+ 此时已切换dev分支，开始在上面开发了
+ 如果是老版本Git，也可以用`git checkout dev`。

---

**4.创建并切换新分支：一条命令搞定**

```git
git switch -c dev
```

相当于：

```git
git branch dev
git switch dev
```

Git 会尝试把`dev`上的改动合并进master，如果没有冲突，会自动完成。

---


**5.合并分支：`git merge`**

切换会主分支后，合并新分支的内容：

```git
git switch main
git merge dev
```

Git 会尝试把`dev`上的改动合并进main，如果没有冲突，会自动完成。

---

**6.删除分支（合并后清理）：`git branch -d`**

```git
git branch -d dev
```

如果你确认合并完了，就可以删掉旧分支。

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

