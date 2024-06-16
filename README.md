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
**並無存檔功能，若結束執行或進入結局必須從頭重新閱讀**，請注意  
  
小說閱讀過程中，user將扮演[洛玥]，為喜愛的小說角色[言煜祁]打抱不平  
後接受神秘力量指引，穿越進小說世界
* 好感度將影響最終結局，請注意好感度累積狀況
## 實作
### features
小說閱讀、顯示圖片
### problem
* 出現兩層以上的巢狀選項迴圈時無法正確跳轉劇本
* 無法正確為角色增加好感度
* 劇本未完成
### cautions
整體程式能夠運作，但bug蠻多  
部分分支後期出現Syntax Error與Segmentation Fault(或double free等狀況)  
遊玩體驗可能不佳
## script
劇本存放於/example-game，分為三個檔案
* script.toml - 主要劇情
* options.toml - 選項分支
* options_script.toml - 分支內劇情
### 格式
* script.toml
  * [scene] 場景
    * [[]]:為第幾幕的哪一個選項分支  
      example: 第一幕第三個選項，選擇《是》→ 劇本轉換至[[first_third.1]]繼續讀取
  * [role] 角色
  * [item] 是否使用物品
    * 不使用物品為none
  * [dialog] 對話內容
  * [choice] 選項連接至第幾幕、有幾個選項  
    example: 第一幕第三個選項→ options.toml讀取[scene]: first_third 的內容
    * 無選項則為none
###### Example
此段為洛玥與林舟(言煜祁特助)於醫院的對話
```
  scene]: hospital
  [role]: LinZhou
  [item]: none
  [dialog]: 洛小姐，好險您只是低血糖，沒事就好。
  [choice]: none
  [scene]: hospital
  [role]: Aside
  [item]: none
  [dialog]: 說話的是方才找醫生的那個男人。
  [choice]: none
  [scene]: hospital
  [role]: LuoYue
  [item]: none
  [dialog]: 謝謝你們，請問你們是…？
  [choice]: none
  [scene]: hospital
  [role]: LinZhou
  [item]: none
  [dialog]: 我叫林舟，這是言氏集團的總裁言煜祁。今天您就是昏倒在總裁的車子旁邊才被我們發現的。
  [choice]: none
```
顯示結果應為
```
林舟
洛小姐，好險您只是低血糖，沒事就好。

旁白
說話的是方才找醫生的那個男人

洛玥
謝謝你們，請問你們是…？

林舟
我叫林舟，這是言氏集團的總裁言煜祁。今天您就是昏倒在總裁的車子旁邊才被我們發現的。
```
* options.toml
  * [scene] 第幾幕第幾次選項分支
  * [num] 第幾個選項的對話內容及後續連接劇情
###### Example
此段為洛玥選擇是否拯救反派喬段
```
# script.toml
[scene]: the_real_world_bathroom
[role]: smartphone_message
[item]: smartphone
[dialog]: 親，收到你的反饋啦！是否願意幫助反派改變命運呢？
[choice]: 2,first_third

# options.toml
[scene]: first_third
[1]: 是
[2]: 否

# options_script.toml
<first_third.1
[scene]: the_real_world_bathroom
[role]: Aside
[item]: smartphone
[dialog]: 看著手機裡的訊息洛玥覺得莫名其妙，正打算不理會這則訊息，卻沒來由的頭暈，一沒留神就點下了屏幕中的【是】，下一秒洛玥人就昏迷過去了，閉上眼的最後一秒，洛玥只有一個念頭。
[choice]: none
[scene]: the_real_world_bathroom
[role]: LuoYue_think
[item]: none
[dialog]: 太生氣到忘記泡澡不能泡太久了…
[choice]: none
[scene]: the_real_world_bathroom
[role]: Aside
[item]: none
[dialog]: 因為暈過去了，洛玥並沒有注意到手機又來了一條訊息…
[choice]: none
[scene]: the_real_world_bathroom
[role]: smartphone_message
[item]: smartphone
[dialog]: 好的，親。正在傳送中呦～祝您任務順利！
[choice]: none
<first_third.1:end
<first_third.2
[scene]: the_real_world_bathroom
[role]: Aside
[item]: smartphone
[dialog]: 看著手機裡的訊息洛玥覺得莫名其妙，打算不理會這則訊息。
[choice]: none
[scene]: the_real_world_bathroom
[role]: LuoYue
[item]: none
[dialog]: 什麼啊，現在真的什麼詐騙手法都有耶…
[choice]: none
[scene]: the_real_world_bathroom
[role]: Aside
[item]: smartphone
[dialog]: 邊想著洛玥邊順手點了【否】。尋思著泡澡時間也差不多了，便起身洗漱上床睡覺補眠去了。
[choice]: none
[scene]: end
[dialog]: <--結局1.-->洛玥未穿越，小說世界未有任何變化 
<first_third.2:end
```
實際運作結果
```
洛玥(手機)
親，收到你的反饋啦！是否願意幫助反派改變命運呢？

[請選擇]
[1]：是
[2]：否

>>選擇是
旁白
看著手機裡的訊息洛玥覺得莫名其妙，正打算不理會這則訊息，卻沒來由的頭暈，一沒留神就點下了屏幕中的【是】，下一秒洛玥人就昏迷過去了，閉上眼的最後一秒，洛玥只有一個念頭。

洛玥(心想)
太生氣到忘記泡澡不能泡太久了…

旁白
因為暈過去了，洛玥並沒有注意到手機又來了一條訊息…

洛玥(手機)
好的，親。正在傳送中呦～祝您任務順利！
[第一章結束]

>>選擇否
旁白
看著手機裡的訊息洛玥覺得莫名其妙，打算不理會這則訊息。

洛玥
什麼啊，現在真的什麼詐騙手法都有耶…

旁白
邊想著洛玥邊順手點了【否】。尋思著泡澡時間也差不多了，便起身洗漱上床睡覺補眠去了。

<--結局1.-->洛玥未穿越，小說世界未有任何變化
[遊戲結束]
```
* options_script.toml
  基本組成與script.toml一致
  上下會加上[第幾幕的哪一個選項分支]與[為第幾幕的哪一個選項分支:end]
  用以判斷此段劇情是否結束
