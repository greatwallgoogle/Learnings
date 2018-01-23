# learngits

## Git命令

### 1. 初始化仓库  
git init——把当前目录变成Git可以管理的仓库，此时当前目录下多了一个.git的目录，这个目录是Git用来跟踪管理版本库的，一般千万不要修改这里面的文件，不然改乱了就会把Git仓库破坏了。  

✲「如果没有看到.git目录，是因为这个目录默认为隐藏的，用ls -ah命令可以查看。」

### 2. 将文件添加到Git仓库，需要两步：   

( 1 ) git add readme.md —— 把readme.md文件添加到仓库，执行此命令后，没有任何显示。  
✲「可反复多次使用，添加多个文件。」

( 2 ) git commit -m "write a readme file"——告诉Git，把文件提交到仓库，备注是"write a readme file"。  
✲「-m后面输入的是本次提交的说明，可以输入任何内容，但最好是有意义的。」

小结：
* 使用 git add filename 将filename对应的文件添加到暂存区
* 使用 git commit -m "commitInfo" 将暂存区中的所有内容提交到当前分支
* 可以理解为将修改的文件存放到暂存区，然后一次性将所有的修改提交到当前分支，即每次提交都是将暂存区中的所有内容提交，如果没有add到暂存区，则当前修改不能被commit到当前分支. 

## 3. 版本回退和重返未来：git reset --hard commit_id  


「HEAD表示当前版本，HEAD^表示上一版本， HEAD^^表示上上个版本，往上100个版本则用HEAD~100表示」

「使用git reset命令回退后，此时再使用git log查看提交日志，则会发现已经没有了回退之前的日志」


*例如我一共提交了3次，分别是commit1、commit2、commit3，我的当前版本是commit3，使用git reset回退到commit2版本，如果此时我想回退到commit3该怎么办？因为一旦回退到commit1，那么通过git log就不能看到commit3的信息，这种情况下怎么解决呢？*

**解决方法：使用git reflog命令**  
 git reflog记录了每次的提交命令，通过```git reflog```找到对应提交信息的commitId。   
 
>  $ git reflog  
b8c9505 HEAD@{0}: reset: moving to HEAD^  ---当前版本   
0235a88 HEAD@{1}: commit: commit3  
b8c9505 HEAD@{2}: commit: commit2  
a765a2e HEAD@{3}: commit: commit1  

如果想要回到commit3对应的版本，即可找到此版本对应的commitId-- ```0235a88```，此时使用```git reset --hard 0235a88```即可回到commit3对应的版本。  

小结：  
* HEAD指向的版本就是当前版本，因此，Git允许我们在版本的历史之间穿梭，使用命令git reset --hard commit_id。

* 穿梭前，用git log可以查看提交历史，以便确定要回退到哪个版本。

* 要重返未来，用git reflog查看命令历史，以便确定要回到未来的哪个版本. 

### 4. 撤销修改:git checkout -- filename  

两种情况：  
1）如果当前修改还未add到暂存区，此时使用```git checkout -- filename```,则本地与版本库中的一模一样。  

2）如果将修改添加到暂存区之后，又做了修改，此时撤销修改回到添加到暂存区之后的状态。 

「撤销修改即回到最近一次git commit或git add时的状态」

3）如果当前修改已经添加到暂存区，若此时需要撤销修改，需要使用```git reset HEAD filename```，此命令表示将当前版本暂存区中的修改撤销，重新放回到工作区。此时接着输入```git status```，此时的状态为：    
```Changes not staged for commit:```  
表示修改已经重新放回工作区。

4）如果从暂存区重新放回到工作区的修改需要继续撤销，那就是从工作区撤销修改的情况了，方法同1）。


小结：
* 情景1：当把本地工作区的某个文件修改乱了，如果想要直接丢弃工作区的所有修改，直接使用```git checkout -- filename```即可。
* 情景2：当把本地的修改添加到暂存区之后，如果此时丢弃添加的修改，需要两步：首先使用 ```git reset HEAD filename```回到场景1，然后按照场景1操作。
* 情景3：如果已经把修改commit到本地分支，想要撤销修改，可以使用版本回退，前提是没有push到远程库。

### 5.  分支  

包括分支的创建、删除、切换、查看、合并、创建并切换和强制删除分支七个命令

（1）创建分支```git branch devname```  
（2）切换分支```git checkout devname```  
（3）查看分支```git branch```  
（4）==创建并切换==到devname对应的分支```git checkout -b devname```  ，```-b```参数表示创建并切换分支。
此命令等同于：   
```
git branch devname
git checkout devname
```

（5）删除分支```git branch -d devname```
（6）合并分支```git merge devname``` 

 注意：如果主分支为master，还有一个分支dev，如果香江dev分支合并到master分支，需要两步：  
 首先```git checkout master```切换到master分支；  
 然后使用```git merge dev```将dev分支合并到master分支
 
（7）强制删除分支```git branch -D devname```  
强制删除分支是指要丢弃一个还没有合并过的分支。
（8）查看分支详解

```
git branch
* dev----------表示当前分支为dev
  master
```

「```git branch```会列出所有的分支，当前分支前面有*符号」


### 6. Bug分支 
一般情况下至少有两个分支工作，一个是主分支master，维护版本稳定。另一个是工作分支，当前所有的工作都是在工作分支上进行。  

如果在工作分支上进行开发工作，此时未完成开发工作，所以不能提交，若这时需要立即修复一个bug，步骤一般是这样的：  
1. 输入```git stash```保存工作分支的状态
2. 切换到master分支
3. 新建并切换到bug分支，例如bug分支名称为bug-101
4. 在bug-101分支上修复bug
5. 切换到主分支master，将bug分支合并到主分支后，删除bug分支
6. 输入```git stash list```查看列表  
7. 两种方法：  
第一种方法：输入```git stash pop```恢复工作分支的状态，这种方式在恢复的同时把stash的内容也删除了。  
第二种方法：输入```git stash apply```恢复，此时不会删除stash的内容，需要输入```git stash drop```命令删除。

此时输入```git stash list```列表中没有内容了。

小结：  
* ```git stash```——保存工作现场
* ```git stash list```——查看保存的工作状态列表
* ```git stash pop```——恢复工作现场，并从stash列表中删除
* ```git stash apply```——恢复工作现场，不删除stash内的保存
* ```git stash drop```——删除stash保存的状态

###  7. 多人协作

工作中经常是团队一起完成任务，这就涉及到多人协作。其工作模式是这样的：
1. 使用```git push origin master```将本地分支的修改推送到远程库。
2. 如果推送失败，使用```git pull```拉去远程库最新数据。
3. 如果出现冲突，解决冲突。
4. 没有冲突或者冲突解决，重新使用步骤1推送。
5. 如果使用```git pull```出现"no tracking information"，说明本地分支与远程分支没有建立关联，可以使用```git branch --set-upstream branch-name origin/branch-name```关联分支。


总结多人协作时常用的命令如下：

- 查看远程库信息```git remote```
- 查看远程库详细信息```git remote -v```
- 将本地分支推送到远程库```git remote origin branch-name```，如果推送失败，使用```git pull```拉去远程库最新的信息，解决冲突后，重新推送
- 在本地创建和远程库对应的分支```git checkout -b branch-name origin/branche-name```，一般将本地分支与远程库分支命名相同
- 将本地已有分支和远程库分支关联```git branch --set-upstream branch-name origin/branch-name```
- 从远程库拉去分支```git pull```


### 8. 其他
（1）查看远程库信息```git remote```
```
$ git remote
origin
```
（2）查看更详细的远程库信息```git remote -v```
```
$ git remote -v
origin	https://github.com/Calence/learngits.git (fetch)
origin	https://github.com/Calence/learngits.git (push)
```
「上面显示了抓取和推送的地址，注意：没有push权限时，不显示push的地址」

（3）推送分支```git push origin master```，表示把本地master分支推送到远程库，```git push origin dev```，表示将dev分支推送到远程库
