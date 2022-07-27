.source teste.txt
.class public test
.super java/lang/Object
.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
return
.end method

.method public static main([Ljava/lang/String;)V
.limit locals 100
.limit stack 100
bipush 1
istore 1
bipush 2
istore 2
bipush 1
istore 3
iload 1
iload 2
bipush 1
iadd
isub
ifgt L_0
goto L_1
L_0:
iload 2
bipush 1
isub
istore 1
L_1:
return
.end method