--- ./base/process/process_iterator_freebsd.cc.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/process/process_iterator_freebsd.cc	2014-05-04 14:38:46.000000000 +0200
@@ -8,6 +8,10 @@
 #include <sys/sysctl.h>
 #include <unistd.h>
 
+/* getuid() */
+#include <unistd.h>
+#include <sys/types.h>
+
 #include "base/logging.h"
 #include "base/strings/string_util.h"
 
