# 这里主要拿来手机一些Qt的神坑:angry:

### 1.QML如果闪屏，别犹豫,直接他妈的把高度(height)加1, 别问为什么，问就是我他妈的也不知道

```javascript
height: ScreenY + 1
```



### 2.QML自定义的comboBox，在弹出框popup的样式中添加padding：1，这他妈也是个坑，不设置成1或者1附近的值，他妈的显示出来靠是喊不居中显示

```javascript
popup:Popup{
    width : m_comboBox.width
    height: 200 * factor
    padding: 1
    .....
    .....
}
```
