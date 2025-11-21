file = open("minor5.tsv", "r")

zip_code_records = {}
city_records = set()

for line in file:
    line = line.strip()
    fields = line.split("\t")

    state, address, city, zip_code = fields
    record = (state, address, city, zip_code)
    # print(record)


    zip_code_record = {}
    city_record = {}

    zip_code_record = (state, address, city, zip_code)
    city_record = (city, zip_code)


    zip_code_records[zip_code] = []
    zip_code_records[zip_code].append(zip_code_record)

    city_records.add((city, zip_code))

    
file.close()

# print(zip_code_records)
# print(city_records)

querying = True
while querying:
    user_input = input("Enter input: ").strip()
    if user_input.isdigit() == True:
        if user_input in zip_code_records:
            for record in zip_code_records[user_input]:
                state, address, city, zip_code = record
                print(f"{address}\n{city}, {state}, {zip_code}")
        else:
            print("No records found in this zip code")

    else:
        user_input = user_input.lower()
        
        if user_input == "quit":
            querying = False
            break
        match = False
        for city, zip_code in city_records:
            if city.lower() == user_input:
                for record in zip_code_records[zip_code]:
                    state, address, ciyt, zip_code = record
                    print(f"{address}\n{city}, {state}, {zip_code}")
                match = True
        if match == False:
            print("No records found in this town")

       
