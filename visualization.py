import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import csv
import seaborn as sns

#Reading csv and putting data into a Dataframe
itc_10 = pd.read_csv(r"itc_10.csv")
itc_100 = pd.read_csv(r"itc_100.csv")
itc_1000 = pd.read_csv(r"itc_1000.csv")

lzw_10 = pd.read_csv(r"lzw_10.csv")
lzw_100 = pd.read_csv(r"lzw_100.csv")
lzw_1000 = pd.read_csv(r"lzw_1000.csv")


#putting coordinates
x1 = itc_10['mssg_size']
x2 = itc_100['mssg_size']
x3 = itc_1000['mssg_size']

x4 = lzw_10['mssg_size']
x5 = lzw_100['mssg_size']
x6 = lzw_1000['mssg_size']

yhuff1 = itc_10[' time']
yrle1 = itc_10[' time_rle']
yrot1 = itc_10['time_rot13']
yrle21 = itc_10['time_rle2']

yhuff2 = itc_100[' time']
yrle2 = itc_100[' time_rle']
yrot2 = itc_100['time_rot13']
yrle22 = itc_100['time_rle2']

yhuff3 = itc_1000[' time']
yrle3 = itc_1000[' time_rle']
yrot3 = itc_1000['time_rot13']
yrle23 = itc_1000['time_rle2']

ylzw1 = lzw_10[' time_lzw']
ylzw2 = lzw_100[' time_lzw']
ylzw3 = lzw_1000[' time_lzw']


#For Huffman
fig, ax = plt.subplots(figsize=(14, 7))
ax.plot(x2, yhuff2, label="Huffman length uptil 100 characters")

ax.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax.set_ylabel('Time', fontsize=16, labelpad=20)

ax.plot(x3, yhuff3, label="Huffman length uptil 1000 characters")

ax.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax.set_ylabel('Time', fontsize=16, labelpad=20)

leg = ax.legend()

#For RLE
fig, ax2 = plt.subplots(figsize=(14, 7))
ax2.plot(x2, yrle2, label="RLE length uptil 100 characters")

ax2.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax2.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax2.set_ylabel('Time', fontsize=16, labelpad=20)

ax2.plot(x3, yrle3, label="RLE length uptil 1000 characters")

ax2.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax2.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax2.set_ylabel('Time', fontsize=16, labelpad=20)

leg = ax2.legend()

#For Rot13
fig, ax3 = plt.subplots(figsize=(14, 7))
ax3.plot(x2, yrot2, label="Rot13 length uptil 100 characters")

ax3.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax3.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax3.set_ylabel('Time', fontsize=16, labelpad=20)

ax3.plot(x3, yrot3, label="Rot13 length uptil 1000 characters")

ax3.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax3.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax3.set_ylabel('Time', fontsize=16, labelpad=20)

leg = ax3.legend()

#For RLE 2nd Implementation
fig, ax4 = plt.subplots(figsize=(14, 7))
ax4.plot(x2, yrle22, label="RLE(vector implementation) length uptil 100 characters")

ax4.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax4.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax4.set_ylabel('Time', fontsize=16, labelpad=20)

ax4.plot(x3, yrle23, label="RLE(vector implementation) length uptil 1000 characters")

ax4.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax4.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax4.set_ylabel('Time', fontsize=16, labelpad=20)

leg = ax4.legend()

#For LZW
fig, ax5 = plt.subplots(figsize=(14, 7))
ax5.plot(x5, ylzw2, label="LZW length uptil 100 characters")

ax5.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax5.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax5.set_ylabel('Time', fontsize=16, labelpad=20)

ax5.plot(x6, ylzw3, label="LZW length uptil 1000 characters")

ax5.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax5.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax5.set_ylabel('Time', fontsize=16, labelpad=20)

leg = ax5.legend()


#For uptill 100 message length for all of them
fig, ax6 = plt.subplots(figsize=(14, 7))
ax6.plot(x2, yhuff2, label="Huffman time for length uptil 100 characters")
ax6.plot(x2, yrle2, label="RLE time for length uptil 100 characters")
ax6.plot(x2, yrot2, label="Rot13 time for length uptil 100 characters")
ax6.plot(x2, yrle22, label="RLE2 time for length uptil 100 characters")
ax6.plot(x2, ylzw2, label="LZW time for length uptil 100 characters")

ax6.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax6.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax6.set_ylabel('Time', fontsize=16, labelpad=20)

leg = ax6.legend()


#For uptill 1000 message length for all of them
fig, ax7 = plt.subplots(figsize=(14, 7))
ax7.plot(x3, yhuff3, label="Huffman time for length uptil 1000 characters")
ax7.plot(x3, yrle3, label="RLE time for length uptil 1000 characters")
ax7.plot(x3, yrot3, label="Rot13 time for length uptil 100 characters")
ax7.plot(x3, yrle23, label="RLE2 time for length uptil 1000 characters")
ax7.plot(x3, ylzw3, label="LZW time for length uptil 1000 characters")

ax7.set_title(r'Message Size vs. Time',fontsize=24, pad=20)
ax7.set_xlabel('Message Size', fontsize=16, labelpad=20)
ax7.set_ylabel('Time', fontsize=16, labelpad=20)

leg = ax7.legend()


#Heat Map
df = itc_10.drop(['mssg_size', 'Unnamed: 5'], axis=1)
df['lzw'] = lzw_10[' time_lzw'].values
print(df)

fig, ax = plt.subplots(figsize=(15,9))  
sns.heatmap(df, annot=True, linewidths=0, cmap="YlGnBu")
