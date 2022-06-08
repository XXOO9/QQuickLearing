@echo off
SetLocal EnableDelayedExpansion
(set PATH=H:\Qt5.12.4\5.12.4\msvc2015_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=H:\Qt5.12.4\5.12.4\msvc2015_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=H:\Qt5.12.4\5.12.4\msvc2015_64\plugins
)
%*
EndLocal
