from datetime import datetime

date_format = "%m/%d/%Y %H:%M:%S"

class Breached():
    def __init__(self, start, username, password, md5_password):
        self._username : str        = username
        self._password : str        = password
        self._md5_password: str     = md5_password
        self._start_time : datetime = start
        self._end_time : datetime   = datetime.now()

    def get_start_time(self):
        return self._start_time

    def get_end_time(self):
        return self._end_time

    def get_username(self):
        return self._username
    
    def get_password(self):
        return self._password

    def get_md5_password(self):
        return self._md5_password

    def get_total_breach_duration(self):
        return self.get_end_time() - self.get_start_time()

    def get_breach_time_sec(self):
        return round(self.get_total_breach_duration().total_seconds(), 2)

    def get_breach_time_min(self):
        return round(self.get_total_breach_duration().total_seconds()/60, 2)

    def get_breach_moment(self):
        return self.get_end_time().strftime(date_format)

    def get_breach_info(self):
        print("\nUsername: {}\
            \nPassword: {}\
            \nEncripted password: {}\
            \nTime of the breach: {}\
            \nTotal duration of the breach: {} hours".format(self.get_username()
                                    , self.get_password()
                                    , self.get_md5_password()
                                    , self.get_breach_moment()
                                    , self.get_total_breach_duration()))
