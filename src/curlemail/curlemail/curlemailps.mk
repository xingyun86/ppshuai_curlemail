
curlpop3ps.dll: dlldata.obj curlpop3_p.obj curlpop3_i.obj
	link /dll /out:curlpop3ps.dll /def:curlpop3ps.def /entry:DllMain dlldata.obj curlpop3_p.obj curlpop3_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del curlpop3ps.dll
	@del curlpop3ps.lib
	@del curlpop3ps.exp
	@del dlldata.obj
	@del curlpop3_p.obj
	@del curlpop3_i.obj
