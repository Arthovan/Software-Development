expenses = {'January':2200, 'February':2350, 'March':2600, 'April':2130, 'May':2190}

print("Feb expenses comparedd to jan:",expenses['February']-expenses['January'])
print("First quarter expenses:",expenses['February']+expenses['January']+expenses['March'])

for key, value in expenses.items():
    if value == 2000:
        print("2000 spent on ",key)

expenses['June'] = 1980
expenses['April'] -= 200

print(expenses)

heros = ['Spider Man', 'Thor', 'Hulk', 'Iron Man', 'Captain America']
print("Length of heros:",len(heros))
heros.append('Black Panther')
print(heros)
heros.remove('Black Panther')
print(heros)
heros.insert(3,'Black Panther')
print(heros)
heros[1:3]=['Doctor Strange']
print(heros)
heros.sort()
print(heros)

max = int(input("Enter the integer: "))
odd_numbers = []
for i in range(1,max):
    if i% 2 == 0:
        odd_numbers.append(i)

print("odd numbers: ",odd_numbers)
