--- mongoose.c
+++ mongoose.c
@@ -1162,19 +1162,6 @@ typedef pid_t process_id_t;
 #define MONGOOSE_IDLE_TIMEOUT_SECONDS 30
 #endif
 
-#ifdef MONGOOSE_NO_SOCKETPAIR
-#define MONGOOSE_NO_CGI
-#endif
-
-#ifdef MONGOOSE_NO_FILESYSTEM
-#define MONGOOSE_NO_AUTH
-#define MONGOOSE_NO_CGI
-#define MONGOOSE_NO_DAV
-#define MONGOOSE_NO_DIRECTORY_LISTING
-#define MONGOOSE_NO_LOGGING
-#define MONGOOSE_NO_SSI
-#endif
-
 struct vec {
   const char *ptr;
   int len;
--- mongoose.h
+++ mongoose.h
@@ -22,6 +22,40 @@
 
 #define MONGOOSE_VERSION "5.4"

+#ifdef MONGOOSE_NO_SOCKETPAIR
+#ifndef MONGOOSE_NO_CGI
+#define MONGOOSE_NO_CGI
+#endif
+#endif
+
+#ifdef MONGOOSE_NO_FILESYSTEM
+#ifndef MONGOOSE_NO_AUTH
+#define MONGOOSE_NO_AUTH
+#endif
+#ifndef MONGOOSE_NO_CGI
+#define MONGOOSE_NO_CGI
+#endif
+#ifndef MONGOOSE_NO_DAV
+#define MONGOOSE_NO_DAV
+#endif
+#ifndef MONGOOSE_NO_DIRECTORY_LISTING
+#define MONGOOSE_NO_DIRECTORY_LISTING
+#endif
+#ifndef MONGOOSE_NO_LOGGING
+#define MONGOOSE_NO_LOGGING
+#endif
+#ifndef MONGOOSE_NO_SSI
+#define MONGOOSE_NO_SSI
+#endif
+#endif
+
+// DAV requires MONGOOSE_NO_DIRECTORY_LISTING
+#ifndef MONGOOSE_NO_DAV
+#ifdef MONGOOSE_NO_DIRECTORY_LISTING
+#undef MONGOOSE_NO_DIRECTORY_LISTING
+#endif
+#endif
+
 #include <stdio.h>      // required for FILE
 #include <stddef.h>     // required for size_t
 
