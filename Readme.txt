第17组-汽车销售系统 运行说明：

方法一：进入目录“可执行文件”，双击 manager.exe
方法二：打开QT，将目录“源码”下的 manger 项目导入，执行编译
           （注意：此方法需要修改 manger.pro，把 LIBS+= -L D:/manager/manager -l ReadDLL 
	此处的路径改为用户此时 manger 项目的路径，再在Debug下拷贝 ReadDLL.dll）

本项目数据库采用 SQLite，无须启动服务器，简单方便易移植
使用者若想可视化本数据库，可以启动 Navicat Premium 等可视化工具查看名为“data.db”的SQL文件