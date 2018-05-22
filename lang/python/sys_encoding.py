# encoding=utf8
import sys
import locale

print sys.getdefaultencoding()    #系统默认编码
print sys.getfilesystemencoding() #文件系统编码
print locale.getdefaultlocale()   #系统当前编码
print sys.stdin.encoding          #终端输入编码
print sys.stdout.encoding         #终端输出编码
