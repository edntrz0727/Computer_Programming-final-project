# Computer_Programming-final-project
本小說閱讀引擎為程式設計(二)課程期末專題  
純屬娛樂，所有圖片資源皆為網路取得，不做營利用途  
## 如何啟動
請先安裝Terminology
開啟終端，執行
```
sudo apt install terminology
```
確認是否成功安裝
```
terminology --version
```
若看到
```
Version: 1.X.X  #依照版本有所不同
```
即安裝成功  
在終端機執行
```
terminology
make
./engine
```
即可啟動程式
## 使用方法
使用鍵盤操作，選項皆有提示數字  
進入主畫面  
* 選擇1.開始閱讀
  可開啟互動小說閱讀  
* 選擇2. 結束閱讀
  結束程式  
**並無存檔功能，若結束執行將從頭重新閱讀**，請注意  
  
小說閱讀過程中，user將扮演[洛玥]，為喜愛的小說角色[言煜祈]打抱不平  
後接受神秘力量指引，穿越進小說世界

* 可以使用[禮物]功能  
選項中可能出現送禮，若送出的禮物符合角色喜好會增加好感度  
好感度將影響最終結局，請注意好感度累積狀況
## 實作
### features
* favor system
* gift system
* endings
### problem
* 
### cautions
## script
劇本存放於/example-game，分為兩個檔案
* script.toml - 主要劇情
* options.toml - 選項分支
### 格式
* script.toml
    * [scene] 場景
    * [role] 角色
    * [item] 是否使用物品
        * 不使用物品為none
    * [dialog] 對話內容
    * [choice] 選項連接至第幾幕、有幾個選項
        * 無選項則為none
* options.toml
    * [scene] 第幾幕
    * [num] 第幾個選項的對話內容及後續連接劇情
