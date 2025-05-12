import bcrypt

class User:
    def __init__(self, password):
        self._password = self._hash_password(password)

    def _hash_password(self, password):
        return bcrypt.hashpw(password.encode(), bcrypt.gensalt())

    def is_valid_password(self, password):
        return bcrypt.checkpw(password.encode(), self._password)


if __name__ == "__main__":
    print("Test User")
    u = User("secret")
    assert u.is_valid_password("secret") is True
    assert u.is_valid_password("wrong") is False
    print("is_valid_password should return True if it's the right password")
