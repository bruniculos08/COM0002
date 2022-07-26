.source input_code.txt
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
.bipush 1
.istore 1
.bipush 2
.istore 2
.iload 1
.iload 2
.bipush 2
.imul
.iadd
.istore 3
.iload 3
.iload 2
.iadd
.istore 2
return
.end method

