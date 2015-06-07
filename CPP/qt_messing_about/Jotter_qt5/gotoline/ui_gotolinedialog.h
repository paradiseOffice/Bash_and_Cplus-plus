<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>GoToLineDialog</class>
 <widget class="QDialog" name="GoToLineDialog">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>184</width>
    <height>79</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Go To Line</string>
  </property>
  <property name="windowIcon">
   <iconset>
    <normaloff>../../../Documents/paradise_office/sandbox_v0.5/view/themes/default_pro_theme/icons/programs/jotter_64x64.png</normaloff>../../../Documents/paradise_office/sandbox_v0.5/view/themes/default_pro_theme/icons/programs/jotter_64x64.png</iconset>
  </property>
  <widget class="QWidget" name="layoutWidget">
   <property name="geometry">
    <rect>
     <x>5</x>
     <y>5</y>
     <width>178</width>
     <height>64</height>
    </rect>
   </property>
   <layout class="QVBoxLayout" name="verticalLayout">
    <item>
     <layout class="QHBoxLayout" name="horizontalLayout">
      <item>
       <widget class="QLabel" name="label">
        <property name="text">
         <string>&amp;Line number:</string>
        </property>
        <property name="buddy">
         <cstring>lineEdit</cstring>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QLineEdit" name="lineEdit"/>
      </item>
     </layout>
    </item>
    <item>
     <widget class="QDialogButtonBox" name="buttonBox">
      <property name="standardButtons">
       <set>QDialogButtonBox::Cancel|QDialogButtonBox::Ok</set>
      </property>
     </widget>
    </item>
   </layout>
  </widget>
 </widget>
 <resources/>
 <connections/>
</ui>
