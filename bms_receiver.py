import time,datetime
import  bms_receiver_utility as bms_utility
def recevie_bms_details():
    final_bms_data = []
    while(True):
        bms_details = input()
        bms_details = bms_utility.format_bms_data(bms_details)
        final_bms_data.append(bms_details)
        final_display_list = bms_utility.calculate_bms_statistics(final_bms_data)
        display_bms_statistics(final_display_list)
        time.sleep(1 / 3)
        if len(final_bms_data) >= 40:
            break


def display_bms_statistics(bms_data):
    if (bms_data):
        print('BMS Parameter details:',datetime.datetime.now().strftime("%d/%m/%Y %H:%M:%S"))
        print('Max Temperature:', bms_data['temperature'][-1])
        print('Min Temperature:', bms_data['temperature'][0])
        print('Average Temperature:', bms_utility.average(bms_data['temperature']))
        print('Max SOC:', bms_data['soc'][-1])
        print('Min SOC:', bms_data['soc'][0])
        print('Average SOC:', bms_utility.average(bms_data['soc']), '\n')

recevie_bms_details()
