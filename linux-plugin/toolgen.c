#include <jni.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "toolgen.h"

#define VERSION "0.1 alpha"
#define HELPER "/toolgen-helper"
#define DEBUG

#ifdef DEBUG
#  define DEBUGOUT(...) fprintf(stderr, __FILE__ " " __VA_ARGS__ )
#else
#  define DEBUGOUT(...)
#endif


char
    dataPath[PATH_MAX] = "/tmp";


JNIEXPORT jstring JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_getVersion(
    JNIEnv *env,
    jclass cls
) {
    jstring result;

    DEBUGOUT("Called getVersion()\n");
    result = (*env)->NewStringUTF(env, VERSION);

    return result;
}


JNIEXPORT jboolean JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_generate(
    JNIEnv *env,
    jclass cls,
    jstring scratchFile
) {
    const char *ptr_str = (*env)->GetStringUTFChars(env, scratchFile, 0);
    int result = JNI_FALSE;
    char helper[PATH_MAX];
    pid_t pid;
    int state;

    strcpy(helper, dataPath);
    strcat(helper, HELPER);

    DEBUGOUT("Called generate(%s)\n", ptr_str);

    DEBUGOUT("  forking...\n");
    pid = vfork();

    if (pid < 0) {
        perror(__FILE__ " fork failed: ");
        DEBUGOUT("  fork failed.\n");
    } else if (pid == 0) {
        DEBUGOUT("  in child, calling helper (%s).\n", helper);
        execl(helper, helper, dataPath, ptr_str, NULL);
        perror(__FILE__ " helper exec failed: ");
        DEBUGOUT("  in child, exec failed.\n");
        _exit(127);
    } else {
        DEBUGOUT("  in parent, waiting for child.\n");
        wait(&state);
        DEBUGOUT("  in parent, child exited, return code=%d.\n", WEXITSTATUS(state));
        if( WEXITSTATUS(state) == 0) {
            result = JNI_TRUE;
        }
    }

    /* cleanup */
    (*env)->ReleaseStringUTFChars(env, scratchFile, ptr_str);

    return result;
}


JNIEXPORT jboolean JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_updateProject(
    JNIEnv *env,
    jclass cls,
    jstring str
) {
    const char *ptr_str = (*env)->GetStringUTFChars(env, str, 0);

    DEBUGOUT("Called updateProject(%s)\n", ptr_str);

    /* cleanup */
    (*env)->ReleaseStringUTFChars(env, str, ptr_str);

    return JNI_FALSE;
}


JNIEXPORT jstring JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_getToolChainVersions(
    JNIEnv *env,
    jclass cls,
    jstring str
) {
    const char *ptr_str = (*env)->GetStringUTFChars(env, str, 0);
    jstring result;

    DEBUGOUT("Called getToolChainVersions(%s)\n", ptr_str);
    result = (*env)->NewStringUTF(env, "");

    /* cleanup */
    (*env)->ReleaseStringUTFChars(env, str, ptr_str);

    return result;
}


JNIEXPORT void JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_setDataPath(
    JNIEnv *env,
    jclass cls,
    jstring path
) {
    const char *ptr_str = (*env)->GetStringUTFChars(env, path, 0);

    DEBUGOUT("Called setDataPath(%s)\n", ptr_str);
    strcpy(dataPath, ptr_str);

    /* cleanup */
    (*env)->ReleaseStringUTFChars(env, path, ptr_str);
}


JNIEXPORT jstring JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_getDataPath(
    JNIEnv *env,
    jclass cls
) {
    jstring result;

    DEBUGOUT("Called getDataPath()\n");
    result = (*env)->NewStringUTF(env, dataPath);

    return result;
}


JNIEXPORT jstring JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_getStartUp(
    JNIEnv *env,
    jclass cls
) {
    jstring result;

    DEBUGOUT("Called getStartUp()\n");
    result = (*env)->NewStringUTF(env, "");

    return result;
}
