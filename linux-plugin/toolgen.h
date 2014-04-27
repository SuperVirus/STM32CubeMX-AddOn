#include <jni.h>

#ifndef __included_toolgen_h
#define __included_toolgen_h

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Get version of this plugin
 *
 * @param env Java interface pointer
 * @param cls Java "this" pointer
 *
 * @return Version string
 */
JNIEXPORT jstring JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_getVersion(
    JNIEnv *env,
    jclass cls
);


/**
 * @brief Generate the output for the toolchain
 *
 * @param env Java interface pointer
 * @param cls Java "this" pointer
 * @param scratchFile Path to scratchfile
 *
 * @return Status
 */
JNIEXPORT jboolean JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_generate(
    JNIEnv *env,
    jclass cls,
    jstring scratchFile
);


/**
 * @brief ???
 *
 * @param env Java interface pointer
 * @param cls Java "this" pointer
 * @param str ???
 *
 * @return ???
 */
JNIEXPORT jboolean JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_updateProject(
    JNIEnv *env,
    jclass cls,
    jstring str
);


/**
 * @brief ???
 *
 * @param env Java interface pointer
 * @param cls Java "this" pointer
 * @param str ???
 *
 * @return ???
 */
JNIEXPORT jstring JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_getToolChainVersions(
    JNIEnv *env,
    jclass cls,
    jstring str
);


/**
 * @brief Set data path of STM32CubeMX
 *
 * @param env Java interface pointer
 * @param cls Java "this" pointer
 * @param path Data path (STM32CubeMX/db/plugins/projectmanager)
 */
JNIEXPORT void JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_setDataPath(
    JNIEnv *env,
    jclass cls,
    jstring path
);


/**
 * @brief ???
 *
 * @param env Java interface pointer
 * @param cls Java "this" pointer
 * @param str ???
 *
 * @return ???
 */
JNIEXPORT jstring JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_getDataPath(
    JNIEnv *env,
    jclass cls
);


/**
 * @brief ???
 *
 * @param env Java interface pointer
 * @param cls Java "this" pointer
 * @param str ???
 *
 * @return ???
 */
JNIEXPORT jstring JNICALL Java_com_st_microxplorer_plugins_projectmanager_model_ToolchainGenerator_getStartUp(
    JNIEnv *env,
    jclass cls
);


#ifdef __cplusplus
}
#endif

#endif
